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

#include <unistd.h>
#include <simulation.h>
#include <signal.h>

int		spawn_child(pid_t *pid, t_threadmsg *msg)
{
	*pid = fork();
	if (*pid == 0)
		philosopher_main(msg);
	else if (*pid == -1)
		return (-1);
	return (0);
}

void	kill_all_children(pid_t *children, int count)
{
	while (count > 0)
	{
		count -= 1;
		kill(children[count], SIGKILL);
	}
}

void	spawn_children(t_simulation *sim)
{
	int			idx;
	t_threadmsg	msg;

	idx = 0;
	msg.sim = sim;
	while (idx < sim->thread_count)
	{
		msg.id = idx + 1;
		msg.meals = 0;
		if (spawn_child(sim->child_processes + idx, &msg) == -1)
		{
			kill_all_children(sim->child_processes, idx);
			throw_fatal("failed to spawn children");
		}
		idx += 1;
	}
}
