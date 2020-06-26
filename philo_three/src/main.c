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
#include <stdlib.h>

t_simulation	g_sim;

int		main(
	int argc,
	char **argv)
{
	if (parse_arguments(&g_sim, argc - 1, argv + 1) != 0)
		return (throw_fatal("bad arguments"));
	if (g_sim.thread_count == 0)
		return (throw_fatal("there should be at least 1 philosopher\n"));
	simulate(&g_sim);
	return (0);
}
