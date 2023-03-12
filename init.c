/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobayashi <kobayashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 08:29:17 by kobayashi         #+#    #+#             */
/*   Updated: 2023/03/12 09:10:52 by kobayashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_e(t_env *e)
{
	e->num = 0;
	e->time_die = 0;
	e->time_eat = 0;
	e->time_sleep = 0;
	e->count_must_eat = -1;
	e->p = NULL;
	e->fork = NULL;
	e->time_start = 0;
	//e->eat_or_die = NULL;
}

int	insert_e(t_env *e, char **argv)
{
	e->num = ft_atoi(argv[1]);
	e->time_die = ft_atoi(argv[2]);
	e->time_eat = ft_atoi(argv[3]);
	e->time_sleep = ft_atoi(argv[4]);
	if (argv[5])
		e->count_must_eat = ft_atoi(argv[5]);
	e->p = (t_philo *)malloc(e->num * sizeof(t_philo));
	if (!e->p)
		return (free_e(e));
	e->fork = (pthread_mutex_t *)malloc(e->num * sizeof(pthread_mutex_t));
	if (!e->fork)
		return (free_e(e));
	e->time_start = get_now();
	//e->eat_or_die = (pthread_mutex_t *)malloc(e->num * sizeof(pthread_mutex_t));
	//if (!e->eat_or_die)
	//	return (free_e(e));
	return (0);
}

void	init_p(t_env *e)
{
	int i;

	i = 0;
	while (i < e->num)
	{
		e->p[i].i = i;
		e->p[i].thread = NULL;
		e->p[i].env = e;
		e->p[i].dead = 0;
		e->p[i].lfork = &e->fork[i];
		e->p[i].rfork = &e->fork[(i + 1) % e->num];
		e->p[i].time_last_eat = get_now();
		//e->p[i].eat_or_die = &e->eat_or_die[i];
		i++;
	}
}

int	init(t_env *e, char **argv)
{
	init_e(e);
	if (insert_e(e, argv))
		return (1);
	init_p(e);
	return (0);
}
