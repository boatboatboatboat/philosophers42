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

#include <stddef.h>
#include <simulation.h>
#include <stdlib.h>

void	*alloc_p(size_t count, size_t type_size)
{
	void	*ptr;

	ptr = malloc(count * type_size);
	if (ptr == NULL)
		throw_fatal("allocation failure");
	return (ptr);
}
