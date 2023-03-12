/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobayashi <kobayashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 08:31:54 by kobayashi         #+#    #+#             */
/*   Updated: 2023/03/11 09:57:44 by kobayashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	is_digit(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (1);
		s++;
	}
	return (0);
}

int	check_arg(int argc, char **argv)
{
	size_t	i;
	int		error;

	error = 0;
	if (!(argc == 5 || argc == 6))
		error = 1;
	i = 1;
	while (!error && argv[i])
		error = is_digit(argv[i++]);
	if (error)
	{
		printf(MESSAGE_ERROR);
		return (1);
	}
	return (0);
}
