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

int	init_stack_mutex(t_simulation *sim)
{
	if (pthread_mutex_init(&sim->writer_lock, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&sim->killed_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&sim->writer_lock);
		return (1);
	}
	return (0);
}

int	init_mutex(t_simulation *sim)
{
	int	i;

	i = 0;
	sim->forks = malloc(sizeof(pthread_mutex_t) * (sim->thread_count + 1));
	if (sim->forks == NULL)
		return (1);
	while (i <= sim->thread_count)
	{
		if (pthread_mutex_init(&sim->forks[i], NULL) != 0)
			break ;
		i += 1;
	}
	if (i <= sim->thread_count)
		while (i >= 0)
		{
			pthread_mutex_destroy(&sim->forks[i]);
			i -= 1;
		}
	return (i < 0);
}

void	destroy_mutex(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i <= sim->thread_count)
	{
		pthread_mutex_destroy(&sim->forks[i]);
		i += 1;
	}
	free(sim->forks);
}
