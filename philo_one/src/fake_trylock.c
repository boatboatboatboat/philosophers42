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

int		fake_trylock(t_threadmsg *m, int forkid)
{
	int	is_busy;

	is_busy = 1;
	pthread_mutex_lock(&m->sim->forks[forkid]);
	if (m->sim->thread_count == 1 || (m->sim->real_forks[forkid] < 0
		&& m->sim->real_forks[forkid] != -m->id))
	{
		m->sim->real_forks[forkid] = m->id;
		is_busy = 0;
	}
	pthread_mutex_unlock(&m->sim->forks[forkid]);
	return (is_busy);
}
