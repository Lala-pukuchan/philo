/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobayashi <kobayashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 10:27:53 by kobayashi         #+#    #+#             */
/*   Updated: 2023/03/12 09:10:57 by kobayashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_thread(t_env *e)
{
	int	i;

	i = 0;
	while (i < e->num)
	{
		pthread_create(\
		&e->p[i].thread, NULL, (void *)&routine, &e->p[i]);
		i++;
	}
}

void	init_mutex(t_env *e)
{
	int	i;

	i = 0;
	while (i < e->num)
		pthread_mutex_init(&e->fork[i++], NULL);
	pthread_mutex_init(&e->eat, NULL);
}

void	launch_philo(t_env *e)
{
	create_thread(e);
	init_mutex(e);
}
