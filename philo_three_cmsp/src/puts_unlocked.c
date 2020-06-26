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
	int	len;
	int	tot;

	len = 0;
	tot = 0;
	while (str[len] != '\0')
		len += 1;
	while (tot != len)
		tot += write(1, str + tot, len - tot);
	return (0);
}
