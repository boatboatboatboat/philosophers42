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

int		fucking_die(t_threadmsg *m)
{
	pthread_mutex_lock(&m->sim->killed_lock);
	m->sim->killed = 1;
	pthread_mutex_unlock(&m->sim->killed_lock);
	println_nd(m, "died\n");
	return (1);
}

int		take_fork(
	t_threadmsg *m,
	unsigned long last_meal,
	int forkid)
{
	unsigned long	curtime;

	while (fake_trylock(m->sim, forkid))
	{
		curtime = get_time_ms();
		if ((curtime - last_meal) >= m->sim->time_to_die)
			return (fucking_die(m));
	}
	return (0);
}

int		do_eat(
	t_threadmsg *m,
	unsigned long *last_meal)
{
	unsigned long	curtime;

	*last_meal = get_time_ms();
	curtime = get_time_ms();
	while ((curtime - *last_meal) < m->sim->time_to_eat)
	{
		if ((curtime - *last_meal) >= m->sim->time_to_die)
			return (fucking_die(m));
		curtime = get_time_ms();
	}
	return (0);
}

int		do_sleep(
		t_threadmsg *m,
		unsigned long last_meal)
{
	unsigned long	curtime;
	unsigned long	sleepstart;

	curtime = get_time_ms();
	sleepstart = get_time_ms();
	while ((curtime - sleepstart) < m->sim->time_to_sleep)
	{
		if ((curtime - last_meal) >= m->sim->time_to_die)
			return (fucking_die(m));
		curtime = get_time_ms();
	}
	return (0);
}

void	drop_forks(t_threadmsg *m, const int forkset[2])
{
	pthread_mutex_lock(&m->sim->forks[forkset[0]]);
	pthread_mutex_lock(&m->sim->forks[forkset[1]]);
	m->sim->real_forks[forkset[0]] = 0;
	m->sim->real_forks[forkset[1]] = 0;
	pthread_mutex_unlock(&m->sim->forks[forkset[1]]);
	pthread_mutex_unlock(&m->sim->forks[forkset[0]]);
}

void	*philosopher(t_threadmsg *m)
{
	int				forkset[2];
	unsigned long	last_meal;

	forkset[0] = m->id == 1 ? 1 : m->id - 1;
	forkset[1] = m->id == 1 ? 0 : m->id % m->sim->thread_count;
	last_meal = get_time_ms();
	while (1)
	{
		//printf("[%d] entry: %lu\n", m->id, entry);
		println(m, "is thinking\n");
		if (take_fork(m, last_meal, forkset[0]) != 0)
			return (NULL);
		println(m, "has taken a fork\n");
		if (take_fork(m, last_meal, forkset[1]) != 0)
			return (NULL);
		println(m, "is eating\n");
		if (do_eat(m, &last_meal) != 0)
			return (NULL);
		drop_forks(m, forkset);
		println(m, "is sleeping\n");
		if (do_sleep(m, last_meal) != 0)
			return (NULL);
		pthread_mutex_lock(&m->meals_lock);
		m->meals += 1;
		pthread_mutex_unlock(&m->meals_lock);
		usleep(500);
	}
}
