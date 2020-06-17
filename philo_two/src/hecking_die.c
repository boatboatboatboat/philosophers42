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

int		hecking_die(t_threadmsg *m)
{
	sem_wait(m->sim->killed_lock);
	m->sim->killed = 1;
	sem_post(m->sim->writer_lock);
	println_nd(m, "died\n");
	return (1);
}
