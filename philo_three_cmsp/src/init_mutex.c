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

void	unlink_semaphores(void)
{
	sem_unlink("/writerlock");
	sem_unlink("/killerlock");
	sem_unlink("/deadlock");
}

int		init_stack_semaphores(t_simulation *sim)
{
	unlink_semaphores();
	sim->writer_lock = sem_open("/writerlock", O_CREAT, S_IRWXU | S_IRWXO, 1);
	sim->killed_lock = sem_open("/killerlock", O_CREAT, S_IRWXU | S_IRWXO, 1);
	sim->dead_lock = sem_open("/deadlock", O_CREAT, S_IRWXU | S_IRWXO, 0);
	if (sim->writer_lock == SEM_FAILED || sim->killed_lock == SEM_FAILED
		|| sim->dead_lock == SEM_FAILED)
	{
		unlink_semaphores();
		return (1);
	}
	return (0);
}
