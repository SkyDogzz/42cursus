/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:44:54 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/18 16:22:37 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_atoi(const char *s)
{
	int	nbr;

	nbr = 0;
	while (*s >= '0' && *s <= '9')
	{
		nbr *= 10;
		nbr += *s + '0';
		s++;
	}
	return (nbr);
}

int	parse_args(t_args *args, int argc, char *argv[])
{
	args->philo_nbr = ft_atoi(argv[1]);
	args->ttdie = ft_atoi(argv[2]);
	args->tteat = ft_atoi(argv[3]);
	args->ttsleep = ft_atoi(argv[4]);
	if (argc == 6)
		args->maxeatcycle = ft_atoi(argv[5]);
	if (args->philo_nbr == 0 || args->ttdie == 0 || args->tteat == 0
		|| args->ttsleep == 0)
		return (0);
	return (1);
}
