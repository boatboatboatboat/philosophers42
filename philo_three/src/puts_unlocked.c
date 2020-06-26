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

int	putstr_unlocked(int fd, const char *str)
{
	int	len;
	int	tot;
	int	res;

	len = 0;
	tot = 0;
	while (str[len] != '\0')
		len += 1;
	while (tot != len)
	{
		res = write(fd, str + tot, len - tot);
		if (res == -1)
			continue ;
		tot += res;
	}
	return (0);
}
