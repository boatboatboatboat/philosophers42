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
#include <stdlib.h>

int	init_threads(t_simulation *sim, t_threadmsg *msg)
{
	int	i;

	sim->threads = malloc(sizeof(pthread_t) * sim->thread_count);
	i = 0;
	while (i < sim->thread_count)
	{
		msg[i].sim = sim;
		msg[i].id = i + 1;
		msg[i].meals = 0;
		if (pthread_mutex_init(&msg[i].meals_lock, NULL) != 0)
			break ;
		if (pthread_create(&sim->threads[i], NULL,
				(void *(*)(void *)) &philosopher, &msg[i]) != 0)
		{
			pthread_mutex_destroy(&msg[i].meals_lock);
			break ;
		}
		i += 1;
	}
	return (i != sim->thread_count);
}
