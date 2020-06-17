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

int		do_eat(
		t_threadmsg *m,
		unsigned long *last_meal)
{
	unsigned long	curtime;

	println(m, "is eating\n");
	*last_meal = get_time_ms();
	curtime = get_time_ms();
	while ((curtime - *last_meal) < m->sim->time_to_eat)
		continue ;
	return (0);
}
