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

int		main(
	int argc,
	char **argv)
{
	t_simulation	*sim;

	sim = malloc(sizeof(t_simulation));
	if (parse_arguments(sim, argc - 1, argv + 1) != 0)
		return (putstr_unlocked("bad arguments\n"));
	if (sim->thread_count == 0)
		return (putstr_unlocked("there should be at least 1 philosopher\n"));
	(void)start_simulation(sim);
	return (0);
}
