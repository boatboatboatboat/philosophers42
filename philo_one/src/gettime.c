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

#include <sys/time.h>
#include <stddef.h>

unsigned long	get_time_ms(void)
{
	struct timeval	tv;
	unsigned long	out;

	gettimeofday(&tv, NULL);
	out = tv.tv_sec;
	out *= 1000;
	out += (tv.tv_usec / 1000);
	return (out);
}

