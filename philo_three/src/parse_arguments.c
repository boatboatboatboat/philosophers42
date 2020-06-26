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

int	parse_arguments(
	t_simulation *sim,
	int argc,
	char **argv)
{
	if (argc != 4 && argc != 5)
		return (1);
	sim->meals_required = -1;
	if (not_atoi(argv[0], &(sim->thread_count)) != 0
		|| not_atoui(argv[1], &(sim->time_to_die)) != 0
		|| not_atoui(argv[2], &(sim->time_to_eat)) != 0
		|| not_atoui(argv[3], &(sim->time_to_sleep)) != 0
		|| (argc == 5 && not_atoi(argv[4], &(sim->meals_required))))
		return (1);
	return (0);
}
