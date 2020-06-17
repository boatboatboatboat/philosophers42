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

int		do_sleep(
		t_threadmsg *m,
		unsigned long last_meal)
{
	unsigned long	curtime;
	unsigned long	sleepstart;

	println(m, "is sleeping\n");
	curtime = get_time_ms();
	sleepstart = get_time_ms();
	while ((curtime - sleepstart) < m->sim->time_to_sleep)
	{
		if ((curtime - last_meal) >= m->sim->time_to_die)
			return (hecking_die(m));
		curtime = get_time_ms();
	}
	return (0);
}
