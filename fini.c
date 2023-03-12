/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobayashi <kobayashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 08:45:14 by kobayashi         #+#    #+#             */
/*   Updated: 2023/03/13 08:39:08 by kobayashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_e(t_env *e)
{
	if (e->p)
	{
		free(e->p);
		e->p = NULL;
	}
	if (e->fork)
	{
		free(e->fork);
		e->fork = NULL;
	}
	if (e)
		free(e);
	return (1);
}

void	fini(t_env *e)
{
	free_e(e);
}
