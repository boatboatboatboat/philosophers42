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

#ifndef SIMUALTION_H
# define SIMULATION_H

# include <semaphore.h>
# include <zconf.h>

# define WRITER_LN "/p3writerlock"
# define DEATH_LN "/p3deathlock"
# define FAILURE_LN "/p3failurelock"
# define MEAL_COMPLETE_SN "/p3mc"
# define LASTMEAL_SN "/p3lm"
# define BARRIER_SN "/p3barrier"
# define FORKS_SN "/p3forks"

typedef struct	s_simulation
{
	sem_t			*writer_lock;
	sem_t			*death_lock;
	sem_t			*failure_lock;
	sem_t			*start_barrier_sem;
	sem_t			**meal_completion_sem;
	sem_t			**lastmeal_locks;
	sem_t			*forks_sem;
	pid_t			*child_processes;
	int				thread_count;
	int				meals_required;
	useconds_t		time_to_die;
	useconds_t		time_to_eat;
	useconds_t		time_to_sleep;
	unsigned long	start_time;
}				t_simulation;

typedef struct	s_threadmsg {
	t_simulation	*sim;
	int				id;
	int				meals;
	unsigned long	last_meal;
}				t_threadmsg;

int		throw_fatal(const char* s);
int		putstr_unlocked(int fd, const char *str);
void	*alloc_p(size_t count, size_t type_size);
sem_t	*new_sem_p(const char *name, int value);
void	philosopher_main(t_threadmsg *message);
void	kill_all_children(pid_t *children, int count);
void	println_nd(t_threadmsg *msg, char *str);
void	println(t_threadmsg *msg, char *str);
int		parse_arguments(
		t_simulation *sim,
		int argc,
		char **argv);
void	simulate(t_simulation *sim);

extern t_simulation	g_sim;

#endif
