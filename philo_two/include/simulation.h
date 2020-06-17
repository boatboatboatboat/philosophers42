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

#ifndef SIMULATION_H
# define SIMULATION_H

# include <pthread.h>
# include <unistd.h>
# include <semaphore.h>

typedef struct		s_simulation
{
	pthread_t		*threads;
	sem_t			*writer_lock;
	sem_t			*killed_lock;
	sem_t			*dead_lock;
	sem_t			*forks;
	int				thread_count;
	int				meals_required;
	int				killed;
	unsigned long	starttime;
	useconds_t		time_to_die;
	useconds_t		time_to_eat;
	useconds_t		time_to_sleep;
}					t_simulation;

typedef struct		s_threadmsg
{
	t_simulation	*sim;
	int				id;
	int				meals;
	unsigned long	last_meal;
	sem_t			*meal_lock;
}					t_threadmsg;

int					parse_arguments(
	t_simulation *sim,
	int argc,
	char **argv);
int					start_simulation(t_simulation *sim);
int					init_mutex(t_simulation *sim);
int					init_stack_mutex(t_simulation *sim);
void				destroy_mutex(t_simulation *sim);
int					init_threads(t_simulation *sim, t_threadmsg *msg);
void				*philosopher(t_threadmsg *info);
void				println(t_threadmsg *msg, char *str);
void				println_nd(t_threadmsg *msg, char *str);
int					not_bzero(int *a, int l);
int					fake_trylock(t_threadmsg *m, int forkid);
int					hecking_die(t_threadmsg *m);
void				drop_forks(t_threadmsg *m);
int					do_eat(
		t_threadmsg *m,
		unsigned long *last_meal);
int					do_sleep(
		t_threadmsg *m,
		unsigned long last_meal);
int					take_fork(
		t_threadmsg *m);
void		dead_lock(t_threadmsg *m);

#endif
