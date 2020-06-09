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
#include <sys/time.h>
#include <stddef.h>
#include <stdio.h>

static void	increase_meal(t_threadmsg *m)
{
	if (m->sim->meals_required >= 0)
	{
		pthread_mutex_lock(&m->meals_lock);
		m->meals += 1;
		pthread_mutex_unlock(&m->meals_lock);
	}
}

void		*philosopher(t_threadmsg *m)
{
	int				forkset[2];
	unsigned long	last_meal;

	forkset[0] = m->id == 1 ? 1 : m->id - 1;
	forkset[1] = m->id == 1 ? 0 : m->id % m->sim->thread_count;
	last_meal = get_time_ms();
	while (1)
	{
		println(m, "is thinking\n");
		take_fork(m, 0, forkset[0]);
		println(m, "has taken a fork\n");
		take_fork(m, 0, forkset[1]);
		println(m, "is eating\n");
		last_meal = get_time_ms();
		pthread_mutex_lock(&m->last_meal_lock);
		m->last_meal = last_meal;
		pthread_mutex_unlock(&m->last_meal_lock);
		usleep(m->sim->time_to_eat * 1000);
		drop_forks(m, forkset);
		println(m, "is sleeping\n");
		increase_meal(m);
		usleep(m->sim->time_to_sleep * 1000);
		if (m->sim->time_to_sleep == 12345678)
			return (NULL);
	}
}
