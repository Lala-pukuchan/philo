/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobayashi <kobayashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:25:40 by kobayashi         #+#    #+#             */
/*   Updated: 2023/03/17 19:51:32 by kobayashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_die(t_env *e, int i)
{
	pthread_mutex_lock(&e->m_print);
	printf("%lu %d %s\n", get_now(), i + 1, MESSAGE_DIE);
	pthread_mutex_unlock(&e->m_print);
}

void	kill_all(t_env *e)
{
	int j = 0;
	while (j < e->num)
	{
		pthread_mutex_lock(&e->die_check);
		e->p[j].dead = 1;
		pthread_mutex_unlock(&e->die_check);
		j++;
	}
}

void	check_philo(t_env *e)
{
	int	i;
	int	sum_eat;

	while (1)
	{
		i = 0;
		sum_eat = 0;
		while (i < e->num)
		{
			pthread_mutex_lock(&e->eat);
			if (get_now() - e->p[i].time_last_eat > e->time_die)
			{
				print_die(e, i);
				e->die = 1;
				kill_all(e);
				pthread_mutex_unlock(&e->eat);
				break ;
			}
			if (e->count_must_eat != -1 && e->p[i].count_eat >= e->count_must_eat)
				sum_eat++;
			pthread_mutex_unlock(&e->eat);
			i++;
		}
		if (e->die)
			break ;
		if (sum_eat >= e->num)
		{
			e->die = 1;
			kill_all(e);
			break ;
		}
	}
}
