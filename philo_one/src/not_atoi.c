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

#include <util.h>

int	not_atoi(char *argv, int *result)
{
	int	num;

	num = 0;
	while (not_isdigit(*argv))
	{
		num *= 10;
		num += *argv - '0';
		argv += 1;
	}
	if (*argv == '\0')
		*result = num;
	return (*argv != '\0');
}

int	not_atoui(char *argv, unsigned int *result)
{
	int	x;

	if (not_atoi(argv, &x))
		return (1);
	*result = (unsigned int)x;
	return (0);
}
