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
#include <stdlib.h>

void	*check_meal_completion(void *simv)
{
	t_simulation	*sim;
	int				idx;

	idx = 0;
	sim = simv;
	while (idx < sim->thread_count)
	{
		sem_wait(sim->meal_completion_sem[idx]);
		idx += 1;
	}
	usleep(500);
	kill_all_children(sim->child_processes, idx);
	exit(EXIT_SUCCESS);
}
