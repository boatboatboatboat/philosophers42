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

void	lock_on_death(t_threadmsg *msg)
{
	sem_wait(msg->sim->pdead_locks[msg->id]);
	sem_post(msg->sim->pdead_locks[msg->id]);
}

void	meal_check(t_threadmsg *msg)
{
	sem_wait(msg->sim->lastmeal_locks[msg->id - 1]);
	msg->last_meal = get_time_ms();
	msg->meals += 1;
	if (msg->sim->meals_required >= 0
		&& msg->meals >= msg->sim->meals_required)
		sem_post(msg->sim->meal_completion_sem[msg->id - 1]);
	sem_post(msg->sim->lastmeal_locks[msg->id - 1]);
}

void	philosopher_core(t_threadmsg *msg)
{
	usleep((msg->id % 2) * 200);
	if (msg->sim->meals_required == 0)
		sem_post(msg->sim->meal_completion_sem[msg->id - 1]);
	while (1)
	{
		println(msg, "is thinking\n");
		lock_on_death(msg);
		sem_wait(msg->sim->forks_sem);
		println(msg, "has taken a fork\n");
		lock_on_death(msg);
		sem_wait(msg->sim->forks_sem);
		println(msg, "is eating\n");
		meal_check(msg);
		usleep(msg->sim->time_to_eat * 1000);
		lock_on_death(msg);
		sem_post(msg->sim->forks_sem);
		sem_post(msg->sim->forks_sem);
		println(msg, "is sleeping\n");
		usleep(msg->sim->time_to_sleep * 1000);
	}
}
