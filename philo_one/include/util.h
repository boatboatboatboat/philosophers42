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

#ifndef UTIL_H
# define UTIL_H

unsigned long	get_time_ms(void);
int				not_atoi(char *str, int *result);
int				not_atoui(char *str, unsigned int *result);
int				not_isdigit(char c);
int				putstr_unlocked(char *str);
unsigned long	get_time_us(void);

#endif
