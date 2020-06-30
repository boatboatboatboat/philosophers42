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

void		dead_lock(t_threadmsg *m)
{
	int	dead;

	sem_wait(m->sim->killed_lock);
	dead = m->sim->killed;
	sem_post(m->sim->killed_lock);
	if (dead)
		sem_wait(m->sim->dead_lock);
}

void		*philosopher(t_threadmsg *m)
{
	unsigned long	last_meal;

	usleep((m->id % 2) * 500);
	while (1)
	{
		println(m, "is thinking\n");
		take_fork(m);
		println(m, "has taken a fork\n");
		take_fork(m);
		println(m, "is eating\n");
		last_meal = get_time_ms();
		dead_lock(m);
		sem_wait(m->meal_lock);
		m->last_meal = last_meal;
		m->meals += 1;
		sem_post(m->meal_lock);
		dead_lock(m);
		stupid_sleep(m->sim->time_to_eat);
		drop_forks(m);
		println(m, "is sleeping\n");
		stupid_sleep(m->sim->time_to_sleep);
	}
}
