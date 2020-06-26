/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/04 13:34:17 by dpattij       #+#    #+#                 */
/*   Updated: 2020/06/04 13:34:17 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <simulation.h>
#include <util.h>
#include <zconf.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <pthread.h>

void	init_semaphores(t_simulation *sim)
{
	int		idx;
	char	buf[128];

	idx = 0;
	sim->meal_completion_sem = alloc_p(sim->thread_count, sizeof(sem_t *));
	sim->lastmeal_locks = alloc_p(sim->thread_count, sizeof(sem_t *));
	sim->child_processes = alloc_p(sim->thread_count, sizeof(pid_t));
	while (idx < sim->thread_count)
	{
		ft_strcpy(buf, MEAL_COMPLETE_SN);
		ft_itoa(idx, buf + sizeof(MEAL_COMPLETE_SN));
		sim->meal_completion_sem[idx] = new_sem_p(buf, 0);
		ft_strcpy(buf, LASTMEAL_SN);
		ft_itoa(idx, buf + sizeof(LASTMEAL_SN));
		sim->lastmeal_locks[idx] = new_sem_p(buf, 1);
		idx += 1;
	}
	sim->writer_lock = new_sem_p(WRITER_LN, 1);
	sim->death_lock = new_sem_p(DEATH_LN, 0);
	sim->failure_lock = new_sem_p(FAILURE_LN, 0);
	sim->start_barrier_sem = new_sem_p(BARRIER_SN, 0);
	sim->forks_sem = new_sem_p(FORKS_SN, sim->thread_count +
		(sim->thread_count == 1));
}

void	*philosopher_check_death(t_threadmsg *msg)
{
	while (1)
	{
		sem_wait(msg->sim->lastmeal_locks[msg->id - 1]);
		if ((get_time_ms() - msg->last_meal) >= msg->sim->time_to_die)
		{
			sem_post(msg->sim->lastmeal_locks[msg->id - 1]);
			println_nd(msg, "died\n");
			sem_post(msg->sim->death_lock);
			return (NULL);
		}
		sem_post(msg->sim->lastmeal_locks[msg->id - 1]);
		usleep(100);
	}
}

void	*check_death(void *simv)
{
	t_simulation	*sim;

	sim = simv;
	sem_wait(sim->death_lock);
	kill_all_children(sim->child_processes, sim->thread_count);
	exit(EXIT_SUCCESS);
}

void	*check_failure(void *simv)
{
	t_simulation	*sim;

	sim = simv;
	sem_wait(sim->failure_lock);
	kill_all_children(sim->child_processes, sim->thread_count);
	exit(EXIT_FAILURE);
}

void	*check_meal_completion(void *simv)
{
	t_simulation	*sim;
	int				idx;

	idx = 0;
	sim = simv;
	while (idx < sim->thread_count)
	{
		sem_wait(sim->meal_completion_sem[idx]);
		idx += 1;
	}
	kill_all_children(sim->child_processes, idx);
	exit(EXIT_SUCCESS);
}

void	philosopher_core(t_threadmsg *msg)
{
	usleep((msg->id % 2) * 200);
	while (1)
	{
		println(msg, "is thinking\n");
		sem_wait(msg->sim->forks_sem);
		println(msg, "has taken a fork\n");
		sem_wait(msg->sim->forks_sem);
		println(msg, "is eating\n");
		sem_wait(msg->sim->lastmeal_locks[msg->id - 1]);
		msg->last_meal = get_time_ms();
		msg->meals += 1;
		if (msg->sim->meals_required >= 0
			&& msg->meals >= msg->sim->meals_required)
			sem_post(msg->sim->meal_completion_sem[msg->id - 1]);
		sem_post(msg->sim->lastmeal_locks[msg->id - 1]);
		usleep(msg->sim->time_to_eat * 1000);
		sem_post(msg->sim->forks_sem);
		sem_post(msg->sim->forks_sem);
		println(msg, "is sleeping\n");
		usleep(msg->sim->time_to_sleep * 1000);
	}
}

void	philosopher_main(t_threadmsg *msg)
{
	pthread_t	dh;

	sem_wait(msg->sim->start_barrier_sem);
	msg->last_meal = get_time_ms();
	if (pthread_create(&dh, NULL, (void *(*)(void *))&philosopher_check_death,
			msg) != 0)
	{
		sem_post(msg->sim->failure_lock);
		while (1)
			continue ;
	}
	philosopher_core(msg);
}

int		spawn_child(pid_t *pid, t_threadmsg *msg)
{
	*pid = fork();
	if (*pid == 0)
		philosopher_main(msg);
	else if (*pid == -1)
		return (-1);
	return (0);
}

void	kill_all_children(pid_t *children, int count)
{
	while (count > 0)
	{
		count -= 1;
		kill(children[count], SIGKILL);
	}
}

void	spawn_children(t_simulation *sim)
{
	int			idx;
	t_threadmsg	msg;

	idx = 0;
	msg.sim = sim;
	while (idx < sim->thread_count)
	{
		msg.id = idx + 1;
		msg.meals = 0;
		if (spawn_child(sim->child_processes + idx, &msg) == -1)
		{
			kill_all_children(sim->child_processes, idx);
			throw_fatal("failed to spawn children");
		}
		idx += 1;
	}
}

void	semaphore_increase(sem_t *sem, int c)
{
	while (c)
	{
		c -= 1;
		sem_post(sem);
	}
}

void	signal_handler(int signal)
{
	kill_all_children(g_sim.child_processes, g_sim.thread_count);
	exit(signal);
}

void	simulate(t_simulation *sim)
{
	pthread_t	threads[3];

	init_semaphores(sim);
	sim->start_time = get_time_ms();
	if (pthread_create(threads, NULL, &check_death, sim) != 0)
		throw_fatal("failed to create death checking thread");
	if (pthread_create(threads + 1, NULL, &check_failure, sim) != 0)
		throw_fatal("failed to create error handling thread");
	if (pthread_create(threads + 2, NULL, &check_meal_completion, sim) != 0)
		throw_fatal("failed to create meal monitoring thread");
	spawn_children(sim);
	signal(SIGKILL, signal_handler);
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	semaphore_increase(sim->start_barrier_sem, sim->thread_count);
	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
	pthread_join(threads[2], NULL);
}
