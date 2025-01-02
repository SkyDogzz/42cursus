/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:17:21 by tstephan          #+#    #+#             */
/*   Updated: 2025/01/02 12:39:16 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	ft_satol(const char *s)
{
	long	res;
	int		mult;

	mult = 1;
	if (!*s)
		return (LONG_MIN);
	if (*s == '-')
		mult = -1;
	if (*s < '0' || *s > '9')
		return (LONG_MIN);
	res = 0;
	while (*s >= '0' && *s <= '9')
	{
		res *= 10;
		res += *s - '0';
		s++;
	}
	return (res);
}

static t_bool	verif_args(t_args *args)
{
	if (args->nb_philo > INT_MAX || args->nb_philo <= 0)
		return (FALSE);
	if (args->time_to_die > INT_MAX || args->time_to_die <= 0)
		return (FALSE);
	if (args->time_to_eat > INT_MAX || args->time_to_eat <= 0)
		return (FALSE);
	if (args->time_to_sleep > INT_MAX || args->time_to_sleep <= 0)
		return (FALSE);
	if (args->nb_each_must_eat > INT_MAX || args->nb_each_must_eat < -1)
		return (FALSE);
	return (TRUE);
}

t_args	*parse_args(int argc, char *argv[])
{
	t_args	*args;

	args = (t_args *)malloc(sizeof(t_args));
	if (!args)
		return (NULL);
	args->nb_philo = ft_satol(argv[1]);
	args->time_to_die = ft_satol(argv[2]);
	args->time_to_eat = ft_satol(argv[3]);
	args->time_to_sleep = ft_satol(argv[4]);
	if (argc == 6)
		args->nb_each_must_eat = ft_satol(argv[5]);
	else
		args->nb_each_must_eat = -1;
	if (!verif_args(args))
	{
		free(args);
		exit_with_error("Bad args");
	}
	return (args);
}
