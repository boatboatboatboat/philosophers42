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

int	putstr_unlocked(char *str)
{
	int	i;
	int	tot;

	i = 0;
	tot = 0;
	while (str[i] != '\0')
		i += 1;
	while (tot != i)
		tot += write(1, str + tot, i - tot);
	return (0);
}
