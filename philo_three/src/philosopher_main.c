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
#include <pthread.h>
#include <util.h>

void	philosopher_main(t_threadmsg *msg)
{
	pthread_t	dh;

	sem_wait(msg->sim->start_barrier_sem);
	msg->last_meal = get_time_ms();
	if (pthread_create(&dh, NULL, (void *(*)(void *))&philosopher_check_death,
			msg) != 0)
	{
		sem_post(msg->sim->failure_lock);
		while (1)
			continue ;
	}
	philosopher_core(msg);
}
