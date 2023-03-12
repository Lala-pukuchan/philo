/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobayashi <kobayashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:59:10 by kobayashi         #+#    #+#             */
/*   Updated: 2023/03/13 08:40:23 by kobayashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_now(void)
{
	struct timeval	v;

	gettimeofday(&v, NULL);
	return ((v.tv_sec) * 1000 + (v.tv_usec) / 1000);
}

void	print(int i, char *m)
{
	printf("%lu %d %s\n", get_now(), i, m);
}

void	take_time(double d, double start)
{
	while (1)
	{
		if (get_now() - start > d)
			break ;
		usleep(10);
	}
}

void	routine(t_philo *p)
{
	if (p->i % 2 == 0)
		take_time(p->env->time_eat, get_now());
	while (1)
	{
		pthread_mutex_lock(p->lfork);
		print(p->i, MESSAGE_FORK);
		pthread_mutex_lock(p->rfork);
		print(p->i, MESSAGE_FORK);
		print(p->i, MESSAGE_EAT);
		pthread_mutex_lock(&p->env->eat);
		p->time_last_eat = get_now();
		pthread_mutex_unlock(&p->env->eat);
		take_time(p->env->time_eat, get_now());
		pthread_mutex_unlock(p->lfork);
		pthread_mutex_unlock(p->rfork);
		print(p->i, MESSAGE_SLEEP);
		take_time(p->env->time_sleep, get_now());
		print(p->i, MESSAGE_THINK);
	}
}
