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

static int	init_simulation(t_simulation *sim, t_threadmsg *tmsg)
{
	sim->starttime = get_time_ms();
	sim->real_forks = malloc(sizeof(int) * sim->thread_count);
	if (sim->real_forks == NULL)
		return (putstr_unlocked("failed to create real forks\n"));
	not_bzero(sim->real_forks, sim->thread_count);
	if (init_mutex(sim) != 0)
		return (putstr_unlocked("mutex creation failed\n"));
	if (init_stack_mutex(sim) != 0)
	{
		destroy_mutex(sim);
		return (putstr_unlocked("stack mutex creation failed\n"));
	}
	if (init_threads(sim, tmsg) != 0)
	{
		pthread_mutex_destroy(&sim->writer_lock);
		pthread_mutex_destroy(&sim->killed_lock);
		destroy_mutex(sim);
		return (putstr_unlocked("thread init failed\n"));
	}
	return (0);
}

void	run_simulation(t_simulation *sim)
{
	while (1)
	{
		pthread_mutex_lock(&sim->killed_lock);
		if (sim->killed)
			break ;
		pthread_mutex_unlock(&sim->killed_lock);
		usleep(500);
/*		i[0] = 0;
		i[1] = 0;
		while (i[0] < sim->thread_count)
		{
			pthread_mutex_lock(&tmsg[i[0]].meals_lock);
			if (tmsg->meals >= sim->meals_required)
				i[1] += 1;
			pthread_mutex_unlock(&tmsg[i[0]].meals_lock);
			pthread_mutex_lock(&tmsg[i[0]].last_meal_lock);
			if ((get_time_ms() - tmsg[i[0]].last_meal) > sim->time_to_die)
			{
				println_nd(tmsg, "fucking died\n");
				return ;
			}
			pthread_mutex_unlock(&tmsg[i[0]].last_meal_lock);
			i[0] += 1;
		}
		if (sim->meals_required >= 0 && i[1] == sim->thread_count)
			break ;
*/
	}
}

void	*fuck(t_threadmsg *msg)
{
	while (1)
	{
		pthread_mutex_lock(&msg->last_meal_lock);
		if ((get_time_ms() - msg->last_meal) >= msg->sim->time_to_die)
		{
			println_nd(msg, "fucking died\n");
			pthread_mutex_lock(&msg->sim->killed_lock);
			msg->sim->killed = 1;
			pthread_mutex_unlock(&msg->sim->killed_lock);
			return (NULL);
		}
		pthread_mutex_unlock(&msg->last_meal_lock);
		usleep(500);
	}
}

void		start_ihandlers(t_threadmsg *msg)
{
	int i;
	pthread_t	some_thread[420];

	i = 0;
	while (i < msg->sim->thread_count)
	{
		pthread_create(&some_thread[i], NULL, (void *(*)(void *)) fuck, msg);
		i += 1;
	}
}

int			start_simulation(t_simulation *sim)
{
	t_threadmsg	*tmsg;

	tmsg = malloc(sizeof(t_threadmsg) * sim->thread_count);
	if (init_simulation(sim, tmsg) != 0)
	{
		free(tmsg);
		free(sim->real_forks);
		return (1);
	}
	sim->killed = 0;
	start_ihandlers(tmsg);
	run_simulation(sim);
	usleep(1010);
	return (0);
}
