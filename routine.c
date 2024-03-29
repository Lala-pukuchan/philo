/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobayashi <kobayashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:59:10 by kobayashi         #+#    #+#             */
/*   Updated: 2023/03/17 20:18:37 by kobayashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_now(void)
{
	struct timeval	v;

	gettimeofday(&v, NULL);
	return ((v.tv_sec) * 1000 + (v.tv_usec) / 1000);
}

void	print(t_philo *p, int i, char *m)
{
	pthread_mutex_lock(&p->env->die_check);
	if (!p->dead)
	{
		pthread_mutex_lock(&p->env->m_print);
		printf("%lu %d %s\n", get_now(), i + 1, m);
		pthread_mutex_unlock(&p->env->m_print);
	}
	pthread_mutex_unlock(&p->env->die_check);
}

void	take_time(t_philo *p, double d, double start)
{
	while (1)
	{
		if (get_now() - start > d)
			break ;
		pthread_mutex_lock(&p->env->die_check);
		if (p->dead)
		{
			pthread_mutex_unlock(&p->env->die_check);
			break ;
		}
		pthread_mutex_unlock(&p->env->die_check);
		usleep(100);
	}
}

void	eat(t_philo *p)
{
	if (p->i % 2 == 0)
		usleep(500);
	pthread_mutex_lock(p->lfork);
	print(p, p->i, MESSAGE_FORK);
	if (p->i % 2 == 0)
		usleep(500);
	pthread_mutex_lock(p->rfork);
	print(p, p->i, MESSAGE_FORK);
	print(p, p->i, MESSAGE_EAT);
	pthread_mutex_lock(&p->env->eat);
	p->time_last_eat = get_now();
	p->count_eat++;
	pthread_mutex_unlock(&p->env->eat);
	take_time(p, p->env->time_eat, get_now());
	pthread_mutex_unlock(p->lfork);
	pthread_mutex_unlock(p->rfork);
}

void	routine(t_philo *p)
{
	if (p->i % 2 == 0)
		take_time(p, p->env->time_eat, get_now());
	while (1)
	{
		eat(p);
		print(p, p->i, MESSAGE_SLEEP);
		take_time(p, p->env->time_sleep, get_now());
		print(p, p->i, MESSAGE_THINK);
		pthread_mutex_lock(&p->env->die_check);
		if (p->dead)
		{
			pthread_mutex_unlock(&p->env->die_check);
			break ;
		}
		pthread_mutex_unlock(&p->env->die_check);
	}
}
