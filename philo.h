/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobayashi <kobayashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 08:15:26 by kobayashi         #+#    #+#             */
/*   Updated: 2023/03/15 21:08:08 by kobayashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define MESSAGE_ERROR "./philo (number_of_philosophers) (time_to_die) \
(time_to_eat) (time_to_sleep) [number_of_times_each_philosopher_must_eat]"
# define MESSAGE_FORK "has taken a fork"
# define MESSAGE_EAT "is eating"
# define MESSAGE_SLEEP "is sleeping"
# define MESSAGE_THINK "is thinking"
# define MESSAGE_DIE "died"

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				i;
	pthread_t		thread;
	struct s_env	*env;
	int				dead;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
	unsigned long	time_last_eat;
	int				count_eat;
}	t_philo;

typedef struct s_env
{
	int				num;
	unsigned long	time_die;
	unsigned long	time_eat;
	unsigned long	time_sleep;
	unsigned long	time_start;
	int				count_must_eat;
	t_philo			*p;
	pthread_mutex_t	*fork;
	pthread_mutex_t	eat;
	int				die;
	pthread_mutex_t	die_check;
}	t_env;

int				ft_isdigit(int c);
int				check_arg(int argc, char **argv);
int				init(t_env *e, char **argv);
int				free_e(t_env *e);
void			fini(t_env *e);
void			launch_philo(t_env *e);
void			end_philo(t_env *e);
void			routine(t_philo *p);
int				ft_atoi(const char *str);
unsigned long	get_now(void);
void			check_philo(t_env *e);

#endif