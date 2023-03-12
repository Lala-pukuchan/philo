/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobayashi <kobayashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:10:29 by kobayashi         #+#    #+#             */
/*   Updated: 2023/03/11 19:10:51 by kobayashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long long	ft_create_int(const char *str)
{
	long long	i;

	i = 0;
	while (*str != '\0' && ft_isdigit(*str))
	{
		i *= 10;
		i += *str - '0';
		str++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	long long	i;
	int			ng;

	i = 0;
	ng = 0;
	while (*str == 32 || (9 <= *str && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			ng++;
		str++;
	}
	i = ft_create_int(str);
	if (ng == 1)
		i *= (-1);
	return ((int)i);
}
