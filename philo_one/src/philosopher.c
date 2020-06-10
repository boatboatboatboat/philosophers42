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

static void	stupid_sleep(unsigned long ms)
{
	unsigned long	entry;

	entry = get_time_us();
	ms *= 1000;
	while ((get_time_us() - entry) < ms)
		usleep(100);
}

void		*philosopher(t_threadmsg *m)
{
	int				forkset[2];
	unsigned long	last_meal;

	forkset[0] = m->id == 1 ? 1 : m->id - 1;
	forkset[1] = m->id == 1 ? 0 : m->id % m->sim->thread_count;
	while (1)
	{
		println(m, "is thinking\n");
		take_fork(m, forkset[0]);
		println(m, "has taken a fork\n");
		take_fork(m, forkset[1]);
		println(m, "is eating\n");
		last_meal = get_time_ms();
		pthread_mutex_lock(&m->meal_lock);
		m->last_meal = last_meal;
		m->meals += 1;
		pthread_mutex_unlock(&m->meal_lock);
		stupid_sleep(m->sim->time_to_eat);
		drop_forks(m, forkset);
		println(m, "is sleeping\n");
		stupid_sleep(m->sim->time_to_sleep);
	}
}
