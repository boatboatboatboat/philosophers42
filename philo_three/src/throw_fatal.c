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

int		throw_fatal(const char *s)
{
	putstr_unlocked(STDERR_FILENO, "error: ");
	putstr_unlocked(STDERR_FILENO, s);
	putstr_unlocked(STDERR_FILENO, "\n");
	exit(1);
	return (0);
}
