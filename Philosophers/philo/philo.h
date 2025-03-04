/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                   |  __ \  ___   __ _ ________   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:02:39 by tstephan          #+#    #+#             */
/*   Updated: 2025/01/07 20:03:29 by tstephan                |___/            */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_args
{
	long	nb_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nb_each_must_eat;
}	t_args;

typedef struct s_philo
{
	int		id;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	
}

int		main(int argc, char *argv[]);
void	exit_with_error(const char *err);
t_args	*parse_args(int argc, char *argv[]);

#endif
