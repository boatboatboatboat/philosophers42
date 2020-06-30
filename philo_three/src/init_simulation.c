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
#include <zconf.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <pthread.h>

static char	*nsn(const char *n, char *buf, int val)
{
	int	len;

	len = 0;
	while (n[len] != '\0')
		len += 1;
	ft_strcpy(buf, n);
	ft_itoa(val, buf + len);
	return (buf);
}

void		init_semaphores(t_simulation *sim)
{
	int		idx;
	char	buf[128];

	idx = 0;
	sim->meal_completion_sem = alloc_p(sim->thread_count, sizeof(sem_t *));
	sim->lastmeal_locks = alloc_p(sim->thread_count, sizeof(sem_t *));
	sim->pdead_locks = alloc_p(sim->thread_count, sizeof(sem_t *));
	sim->child_processes = alloc_p(sim->thread_count, sizeof(pid_t));
	while (idx < sim->thread_count)
	{
		sim->meal_completion_sem[idx] =
				new_sem_p(nsn(MEAL_COMPLETE_SN, buf, idx), 0);
		sim->lastmeal_locks[idx] = new_sem_p(nsn(LASTMEAL_SN, buf, idx), 1);
		sim->pdead_locks[idx] = new_sem_p(nsn(PDEAD_SN, buf, idx), 1);
		idx += 1;
	}
	sim->writer_lock = new_sem_p(WRITER_LN, 1);
	sim->death_lock = new_sem_p(DEATH_LN, 0);
	sim->failure_lock = new_sem_p(FAILURE_LN, 0);
	sim->start_barrier_sem = new_sem_p(BARRIER_SN, 0);
	sim->forks_sem = new_sem_p(FORKS_SN, sim->thread_count +
		(sim->thread_count == 1));
}

void		semaphore_increase(sem_t *sem, int c)
{
	while (c)
	{
		c -= 1;
		sem_post(sem);
	}
}

void		simulate(t_simulation *sim)
{
	pthread_t	threads[3];

	init_semaphores(sim);
	sim->start_time = get_time_ms();
	if (pthread_create(threads, NULL, &check_death, sim) != 0)
		throw_fatal("failed to create death checking thread");
	if (pthread_create(threads + 1, NULL, &check_failure, sim) != 0)
		throw_fatal("failed to create error handling thread");
	if (pthread_create(threads + 2, NULL, &check_meal_completion, sim) != 0)
		throw_fatal("failed to create meal monitoring thread");
	spawn_children(sim);
	semaphore_increase(sim->start_barrier_sem, sim->thread_count);
	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
	pthread_join(threads[2], NULL);
}
