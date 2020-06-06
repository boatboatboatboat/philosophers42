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
			return (hecking_die(m));
	}
	return (0);
}
