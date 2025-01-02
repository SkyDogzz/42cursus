/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:03:36 by tstephan          #+#    #+#             */
/*   Updated: 2025/01/02 12:31:02 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_args	*args;

	if (argc < 5 || argc > 6)
		exit_with_error("Usage: %s <nb_philo> <time_to_die> <time_to_eat> \
<time_to_sleep> [nb_each_must_eat]");
	args = parse_args(argc, argv);
	free(args);
	return (EXIT_SUCCESS);
}
