/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:25:03 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/18 16:27:00 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	wrong_args(const char *name)
{
	printf("Usage: %s number_of_philosophers time_to_die time_to_eat ", name);
	printf("time_to_sleep [number_of_times_each_philosopher_must_eat]");
}

void	free_philos(t_philos *philos, int pos)
{
	(void) philos;
	(void) pos;
}

int	init_philos(t_philos *philos, t_args *args)
{
	int		pos;
	t_philo	*philo;

	philos = (t_philos *)malloc(sizeof(t_philo));
	if (!philos)
		return (0);
	philos->top = (t_philo *)malloc(sizeof(t_philo));
	if (!philos->top)
	{
		free_philos(philos, 0);
	}
	pos = 1;
	philo = philos->top;
	while (pos < args->philo_nbr)
	{
		philo->next = (t_philo *)malloc(sizeof(t_philo));
		if (!philo->next)
			free_philos(philos, pos);
		pos++;
		philo = philo->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_args		*args;
	t_philos	*philos;

	if (argc != 5 && argc != 6)
	{
		wrong_args(argv[0]);
		return (EXIT_FAILURE);
	}
	args = (t_args *)malloc(sizeof(t_args));
	if (!args)
	{
		printf("Init args error");
		return (EXIT_FAILURE);
	}
	if (!parse_args(args, argc, argv))
	{
		printf("Bad args");
		return (EXIT_FAILURE);
	}
	philos = NULL;
	if (!init_philos(philos, args))
	{
		printf("Philo init failed");
		return (EXIT_FAILURE);
	}
	free_philos(philos, args->philo_nbr);
	return (EXIT_SUCCESS);
}
