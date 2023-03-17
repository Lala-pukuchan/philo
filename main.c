/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobayashi <kobayashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 08:15:13 by kobayashi         #+#    #+#             */
/*   Updated: 2023/03/17 20:00:59 by kobayashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_env	*e;

	if (check_arg(argc, argv))
		return (1);
	e = (t_env *)malloc(sizeof(t_env));
	if (!e)
		return (1);
	if (init(e, argv))
		return (1);
	launch_philo(e);
	check_philo(e);
	end_philo(e);
	fini(e);
	return (0);
}
