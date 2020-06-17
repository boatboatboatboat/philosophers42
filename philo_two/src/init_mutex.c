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

int		init_stack_mutex(t_simulation *sim)
{
	sem_unlink("/writerlock");
	sem_unlink("/killerlock");
	sim->writer_lock = sem_open("/writerlock", O_CREAT, S_IRWXU | S_IRWXO, 1);
	sim->killed_lock = sem_open("/killerlock", O_CREAT, S_IRWXU | S_IRWXO, 1);
	sim->dead_lock = sem_open("/deadlock", O_CREAT, S_IRWXU | S_IRWXO, 0);
	/*	if (pthread_mutex_init(&sim->writer_lock, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&sim->killed_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&sim->writer_lock);
		return (1);
	}*/
	return (0);
}
