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
#include <fcntl.h>

sem_t	*new_sem_p(const char *name, int value)
{
	sem_t	*new_semaphore;

	sem_unlink(name);
	new_semaphore = sem_open(name, O_CREAT, S_IRWXU | S_IRWXO, value);
	if (new_semaphore == SEM_FAILED)
		throw_fatal("failed to create semaphore");
	return (new_semaphore);
}
