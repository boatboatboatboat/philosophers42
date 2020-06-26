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
#include <stdio.h>
#include <stdlib.h>
#include <util.h>
#include <signal.h>

static int	init_simulation(t_simulation *sim, t_threadmsg *tmsg)
{
	sim->starttime = get_time_ms();
	sem_unlink("/philoforks");
	sim->forks = sem_open("/philoforks", O_CREAT | O_TRUNC, S_IRWXU | S_IRWXO,
			sim->thread_count + (sim->thread_count == 1));
	if (sim->forks == NULL)
		return (putstr_unlocked("failed to create forks\n"));
	if (init_stack_semaphores(sim) != 0)
		return (putstr_unlocked("stack mutex creation failed\n"));
	if (init_threads(sim, tmsg) != 0)
	{
		unlink_semaphores();
		return (putstr_unlocked("thread init failed\n"));
	}
	return (0);
}

void		death_event_handler(t_simulation *sim, t_threadmsg *msg)
{
	sem_wait(msg->died_sem);
	sem_wait(msg->sim->killed_lock);
	msg->sim->killed = 1;
	sem_post(msg->sim->killed_lock);
	exit(0);
}

void		mealcomplete_event_handler(t_simulation *sim, t_threadmsg *msg)
{
	int	i;

	i = 0;
	while (i < sim->thread_count)
	{
		sem_wait(msg[i].meals_completed_sem);
		i += 1;
	}
	kill_em_all(sim, sim->thread_count);
	exit(0);
}

void		start_philosopher(t_simulation *sim, t_threadmsg *msg)
{
	pthread_t	ihandler;

	if (pthread_create(&ihandler, NULL, (void *(*)(void *)) ihandler, msg) != 0)
		sem_post(sim->failure_lock);
	else
		philosopher(msg);
	exit(0);
}

void		kill_em_all(t_simulation *sim, int c)
{
	while (c > 0)
	{
		c -= 1;
		kill(sim->children[c], SIGKILL);
	}
}

void		run_simulation(t_simulation *sim, t_threadmsg *msg)
{
	int	i;

	i = 0;
	while (i < sim->thread_count)
	{
		sim->children[i] = fork();
		if (sim->children[i] == 0)
			start_philosopher(sim, msg + i);
		else if (sim->children[i] < 0)
		{
			kill_em_all(sim, i);
			break ;
		}
		i += 1;
	}
}

void		*ihandler(t_threadmsg *msg)
{
	while (1)
	{
		sem_wait(msg->meal_lock);
		if ((get_time_ms() - msg->last_meal) >= msg->sim->time_to_die)
		{
			sem_post(msg->meal_lock);
			println_nd(msg, "died\n");
			sem_wait(msg->sim->killed_lock);
			msg->sim->killed = 1;
			sem_post(msg->sim->killed_lock);
			return (NULL);
		}
		sem_post(msg->meal_lock);
		usleep(100);
	}
}

int			start_ihandlers(t_threadmsg *msg)
{
	int			i;
	pthread_t	some_thread;

	i = 0;
	while (i < msg->sim->thread_count)
	{
		if (pthread_create(&some_thread, NULL,
				(void *(*)(void *)) ihandler, &msg[i]) != 0)
			return (1);
		i += 1;
	}
	return (0);
}

int			start_simulation(t_simulation *sim)
{
	t_threadmsg	*tmsg;

	tmsg = malloc(sizeof(t_threadmsg) * sim->thread_count);
	if (init_simulation(sim, tmsg) != 0)
	{
		free(tmsg);
		unlink_semaphores();
		return (1);
	}
	sim->killed = 0;
	start_ihandlers(tmsg);
	run_simulation(sim, tmsg);
	usleep(1010);
	return (0);
}
