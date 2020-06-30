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

void	*philosopher_check_death(t_threadmsg *msg)
{
	while (1)
	{
		sem_wait(msg->sim->lastmeal_locks[msg->id - 1]);
		if ((get_time_ms() - msg->last_meal) >= msg->sim->time_to_die)
		{
			sem_post(msg->sim->lastmeal_locks[msg->id - 1]);
			println_nd(msg, "died\n");
			sem_post(msg->sim->death_lock);
			return (NULL);
		}
		sem_post(msg->sim->lastmeal_locks[msg->id - 1]);
		usleep(100);
	}
}
