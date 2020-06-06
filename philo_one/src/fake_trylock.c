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

int		fake_trylock(t_simulation *sim, int forkid)
{
	int	is_busy;

	is_busy = 1;
	pthread_mutex_lock(&sim->forks[forkid]);
	if (sim->real_forks[forkid] == 0)
	{
		sim->real_forks[forkid] = 1;
		is_busy = 0;
	}
	pthread_mutex_unlock(&sim->forks[forkid]);
	return (is_busy);
}
