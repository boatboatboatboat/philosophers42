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
#include <sys/time.h>

int	start_simulation(t_simulation *sim)
{
	t_threadmsg		*tmsg;
	int				i[2];

	sim->starttime = get_time_ms();
	sim->real_forks = malloc(sizeof(int) * (sim->thread_count + 1));
	if (sim->real_forks == NULL)
		return (putstr_unlocked("failed to create real forks\n"));
	not_bzero(sim->real_forks, sim->thread_count + 1);
	tmsg = malloc(sizeof(t_threadmsg) * (sim->thread_count));
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
	sim->killed = 0;
	while (1)
	{
		pthread_mutex_lock(&sim->killed_lock);
		if (sim->killed)
			break ;
		pthread_mutex_unlock(&sim->killed_lock);
		i[0] = 0;
		i[1] = 0;
		while (i[0] < sim->thread_count)
		{
			if (sim->meals_required >= 0)
			{
				pthread_mutex_lock(&tmsg[i[0]].meals_lock);
				if (tmsg->meals >= sim->meals_required)
					i[1] += 1;
				pthread_mutex_unlock(&tmsg[i[0]].meals_lock);
			}
			i[0] += 1;
		}
		if (i[1] == sim->thread_count)
			break ;
	}
	usleep(1010);
	return (0);
}
