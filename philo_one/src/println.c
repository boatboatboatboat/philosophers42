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
#include <sys/time.h>
#include <simulation.h>
#include <stdio.h>

static int	number_length(int n)
{
	int     tens;

	if (n == 0)
		return (1);
	tens = n < 0;
	while (n != 0)
	{
		n /= 10;
		tens += 1;
	}
	return (tens);
}

char		*ft_itoa(unsigned long n, char *out)
{
	int				head;
	unsigned long	real_n;

	head = number_length(n);
	out[0] = '0';
	out[head] = '\0';
	real_n = n;
	while (real_n != 0)
	{
		head -= 1;
		out[head] = real_n % 10 + '0';
		real_n /= 10;
	}
	return (out);
}

void	println_nd(t_threadmsg *msg, char *str)
{
	char			itoabuf[128];

	ft_itoa(get_time_ms() - msg->sim->starttime, itoabuf);
	pthread_mutex_lock(&msg->sim->writer_lock);
    putstr_unlocked(itoabuf);
    putstr_unlocked(" ");
	ft_itoa(msg->id, itoabuf);
    putstr_unlocked(itoabuf);
    putstr_unlocked(" ");
    putstr_unlocked(str);
}

void	println(t_threadmsg *msg, char *str)
{
	char			itoabuf[128];

	ft_itoa(get_time_ms() - msg->sim->starttime, itoabuf);
	pthread_mutex_lock(&msg->sim->writer_lock);
    putstr_unlocked(itoabuf);
    putstr_unlocked(" ");
	ft_itoa(msg->id, itoabuf);
    putstr_unlocked(itoabuf);
    putstr_unlocked(" ");
    putstr_unlocked(str);
	pthread_mutex_unlock(&msg->sim->writer_lock);
}
