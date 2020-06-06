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

void	drop_forks(t_threadmsg *m, const int forkset[2])
{
	pthread_mutex_lock(&m->sim->forks[forkset[0]]);
	pthread_mutex_lock(&m->sim->forks[forkset[1]]);
	m->sim->real_forks[forkset[0]] = 0;
	m->sim->real_forks[forkset[1]] = 0;
	pthread_mutex_unlock(&m->sim->forks[forkset[1]]);
	pthread_mutex_unlock(&m->sim->forks[forkset[0]]);
}
