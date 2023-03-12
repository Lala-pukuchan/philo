/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobayashi <kobayashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:25:40 by kobayashi         #+#    #+#             */
/*   Updated: 2023/03/12 09:09:15 by kobayashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	kill_all(t_env *e)
{
	int	i;

	i = 0;
	(void)i; (void)e;
	//while (i < e->num)
	//	e->die[i] = 1;
		//e->p[i++].dead = 1;
	return (1);
}

int	check_philo(t_env *e)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < e->num)
		{
			//pthread_mutex_lock(e->p[i].eat_or_die);
			pthread_mutex_lock(&e->eat);
			//if (e->p[i].time_last_eat - get_now() > e->time_die)
			printf("last_meal: %lu\n", e->p[i].time_last_eat);
			//pthread_mutex_unlock(e->p[i].eat_or_die);
			pthread_mutex_unlock(&e->eat);
			i++;
		}
	}
}