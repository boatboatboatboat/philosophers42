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

int	init_threads(t_simulation *sim, t_threadmsg *msg)
{
	int	i;
	int	fail;

	sim->threads = malloc(sizeof(pthread_t) * sim->thread_count);
	i = 0;
	fail = 0;
	while (i < sim->thread_count)
	{
		msg[i].sim = sim;
		msg[i].id = i + 1;
		msg[i].meals = 0;
		msg[i].last_meal = get_time_ms();
		if (pthread_mutex_init(&msg[i].meals_lock, NULL) != 0)
		{
			fail = 1;
			break ;
		}
		if (pthread_mutex_init(&msg[i].last_meal_lock, NULL) != 0)
		{
			fail = 1;
			break ;
		}
		i += 1;
	}
	while (i > 0)
	{
		i -= 1;
		if (pthread_create(&sim->threads[i], NULL,
				(void *(*)(void *)) &philosopher, &msg[i]) != 0)
		{
			pthread_mutex_destroy(&msg[i].meals_lock);
			fail = 1;
			break ;
		}
	}
	return (fail);
}
