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
	pthread_mutex_lock(&m->meals_lock);
	m->meals += 1;
	pthread_mutex_unlock(&m->meals_lock);
}

static void	yield_until_gprio_equal(
		t_threadmsg *m, int lprio, unsigned long last_meal)
{
	int	should_yield;

	should_yield = 1;
	while (should_yield)
	{
		pthread_mutex_lock(&m->sim->gprio_lock);
		if (m->sim->gprio >= lprio || (get_time_ms() - last_meal) >=
			m->sim->time_to_eat + m->sim->time_to_sleep)
			should_yield = 0;
		pthread_mutex_unlock(&m->sim->gprio_lock);
		println(m, "unyielded\n");
	}
}

void		*philosopher(t_threadmsg *m)
{
	int				forkset[2];
	unsigned long	last_meal;
	int				lprio;

	lprio = 0;
	forkset[0] = m->id == 1 ? 1 : m->id - 1;
	forkset[1] = m->id == 1 ? 0 : m->id % m->sim->thread_count;
	last_meal = get_time_ms();
	while (1)
	{
		yield_until_gprio_equal(m, lprio, last_meal);
		println(m, "is thinking\n");
		if (take_fork(m, last_meal, forkset[0]) != 0)
			return (NULL);
		println(m, "has taken a fork\n");
		if (take_fork(m, last_meal, forkset[1]) != 0)
			return (NULL);
		if (do_eat(m, &last_meal) != 0)
			return (NULL);
		drop_forks(m, forkset);
		if (do_sleep(m, last_meal) != 0)
			return (NULL);
		increase_meal(m);
		lprio += 1;
	}
}
