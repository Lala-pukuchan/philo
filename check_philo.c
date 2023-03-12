/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobayashi <kobayashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:25:40 by kobayashi         #+#    #+#             */
/*   Updated: 2023/03/13 08:38:31 by kobayashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philo(t_env *e)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < e->num)
		{
			pthread_mutex_lock(&e->eat);
			printf("last_meal: %lu\n", e->p[i].time_last_eat);
			pthread_mutex_unlock(&e->eat);
			i++;
		}
	}
}
