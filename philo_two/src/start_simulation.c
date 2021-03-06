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
#include <fcntl.h>

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

void		run_simulation(t_simulation *sim, t_threadmsg *msg)
{
	unsigned long	i[2];

	while (1)
	{
		sem_wait(sim->killed_lock);
		if (sim->killed)
			break ;
		sem_post(sim->killed_lock);
		i[0] = 0;
		i[1] = 0;
		while (i[0] < (unsigned long)sim->thread_count)
		{
			sem_wait(msg[i[0]].meal_lock);
			i[1] += msg[i[0]].meals >= sim->meals_required;
			sem_post(msg[i[0]].meal_lock);
			i[0] += 1;
		}
		if (sim->meals_required >= 0
			&& i[1] == (unsigned long)sim->thread_count)
		{
			sem_wait(sim->writer_lock);
			break ;
		}
		usleep(500);
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
	if (tmsg == NULL || init_simulation(sim, tmsg) != 0)
	{
		free(tmsg);
		unlink_semaphores();
		return (1);
	}
	sim->killed = 0;
	start_ihandlers(tmsg);
	run_simulation(sim, tmsg);
	usleep(1010);
	free(tmsg);
	unlink_semaphores();
	return (0);
}
