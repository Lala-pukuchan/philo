/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobayashi <kobayashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:56:38 by kobayashi         #+#    #+#             */
/*   Updated: 2023/03/13 08:38:58 by kobayashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_thread(t_env *e)
{
	int	i;

	i = 0;
	while (i < e->num)
		pthread_join(e->p[i++].thread, NULL);
}

void	destroy_mutex(t_env *e)
{
	int	i;

	i = 0;
	while (i < e->num)
	{
		pthread_mutex_destroy(&e->fork[i++]);
		pthread_mutex_destroy(&e->eat_or_die[i++]);
	}
}

void	end_philo(t_env *e)
{
	join_thread(e);
	destroy_mutex(e);
}
