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
#include <stdlib.h>

static int	init_messages(t_simulation *sim, t_threadmsg *msg)
{
	int	idx;
	int	failed;

	idx = 0;
	failed = 0;
	while (idx < sim->thread_count)
	{
		msg[idx].sim = sim;
		msg[idx].id = idx + 1;
		msg[idx].meals = 0;
		msg[idx].last_meal = get_time_ms();
		if (pthread_mutex_init(&msg[idx].meal_lock, NULL) != 0)
		{
			failed = 1;
			break ;
		}
		idx += 1;
	}
	while (failed && idx > 0)
	{
		idx -= 1;
		pthread_mutex_destroy(&msg[idx].meal_lock);
	}
	return (failed);
}

static int	create_threads(t_simulation *sim, t_threadmsg *msg)
{
	int	idx;
	int	fail;

	idx = 0;
	fail = 0;
	while (idx < sim->thread_count)
	{
		if (pthread_create(&sim->threads[idx], NULL,
				(void *(*)(void *)) &philosopher, &msg[idx]) != 0)
		{
			fail = 1;
			break ;
		}
		idx += 1;
	}
	return (fail);
}

int			init_threads(t_simulation *sim, t_threadmsg *msg)
{
	sim->threads = malloc(sizeof(pthread_t) * sim->thread_count);
	if (sim->threads == NULL)
		return (1);
	if (init_messages(sim, msg) != 0)
	{
		free(sim->threads);
		return (1);
	}
	if (create_threads(sim, msg) != 0)
		return (1);
	return (0);
}
