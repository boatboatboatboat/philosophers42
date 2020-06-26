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

static int	number_length(unsigned long n)
{
	int	tens;

	if (n == 0)
		return (1);
	tens = 0;
	while (n != 0)
	{
		n /= 10;
		tens += 1;
	}
	return (tens);
}

char		*ft_strcpy(char *dst, const char *src)
{
	int	idx;

	idx = 0;
	while (src[idx] != '\0')
	{
		dst[idx] = src[idx];
		idx += 1;
	}
	return (dst);
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

void		println_nd(t_threadmsg *msg, char *str)
{
	char			itoabuf[128];

	ft_itoa(get_time_ms() - msg->sim->start_time, itoabuf);
	sem_wait(msg->sim->writer_lock);
	putstr_unlocked(STDOUT_FILENO, itoabuf);
	putstr_unlocked(STDOUT_FILENO, " ");
	ft_itoa(msg->id, itoabuf);
	putstr_unlocked(STDOUT_FILENO, itoabuf);
	putstr_unlocked(STDOUT_FILENO, " ");
	putstr_unlocked(STDOUT_FILENO, str);
}

void		println(t_threadmsg *msg, char *str)
{
	char			itoabuf[128];

	ft_itoa(get_time_ms() - msg->sim->start_time, itoabuf);
	sem_wait(msg->sim->writer_lock);
	putstr_unlocked(STDOUT_FILENO, itoabuf);
	putstr_unlocked(STDOUT_FILENO, " ");
	ft_itoa(msg->id, itoabuf);
	putstr_unlocked(STDOUT_FILENO, itoabuf);
	putstr_unlocked(STDOUT_FILENO, " ");
	putstr_unlocked(STDOUT_FILENO, str);
	sem_post(msg->sim->writer_lock);
}
