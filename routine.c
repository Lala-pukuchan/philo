/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobayashi <kobayashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:59:10 by kobayashi         #+#    #+#             */
/*   Updated: 2023/03/12 09:10:03 by kobayashi        ###   ########.fr       */
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
	// finish check
	// print mutex
	printf("%lu %d %s\n", get_now(), i, m);
}

void	take_time(int n, double d, double start)
{
	(void)n;
	// finish check
	while (1)
	{
		if (get_now() - start > d)
			break ;
		usleep(10);
	}
}

void	routine(t_philo *p)
{
	// for dead lock
	if (p->i % 2 == 0)
		take_time(p->env->num, p->env->time_eat, get_now());
	// finish check
	while (1)
	{
		// eat
		pthread_mutex_lock(p->lfork);
		print(p->i, MESSAGE_FORK);
		pthread_mutex_lock(p->rfork);
		print(p->i, MESSAGE_FORK);

		print(p->i, MESSAGE_EAT);
		//pthread_mutex_lock(p->eat_or_die);
		pthread_mutex_lock(&p->env->eat);
		p->time_last_eat = get_now();
		//pthread_mutex_unlock(p->eat_or_die);
		pthread_mutex_lock(&p->env->eat);

		take_time(p->env->num, p->env->time_eat, get_now());
		pthread_mutex_unlock(p->lfork);
		pthread_mutex_unlock(p->rfork);

		// sleep
		print(p->i, MESSAGE_SLEEP);
		take_time(p->env->num, p->env->time_sleep, get_now());

		// think
		print(p->i, MESSAGE_THINK);
	}
}
