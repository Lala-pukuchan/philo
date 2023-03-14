/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobayashi <kobayashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:25:40 by kobayashi         #+#    #+#             */
/*   Updated: 2023/03/14 21:29:54 by kobayashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_philo(t_env *e)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < e->num)
		{
			pthread_mutex_lock(&e->eat);
			if (get_now() - e->p[i].time_last_eat > e->time_die)
			{
				e->die = 1;
				break ;
			}
			pthread_mutex_unlock(&e->eat);
			i++;
		}
		if (e->die)
			break ;
	}
}
