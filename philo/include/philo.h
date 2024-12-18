/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:25:33 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/18 16:24:48 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_args
{
	int	philo_nbr;
	int	ttdie;
	int	tteat;
	int	ttsleep;
	int	maxeatcycle;
}	t_args;

typedef struct s_philo
{
	struct s_philo	*previous;
	struct s_philo	*next;
}	t_philo;

typedef struct s_philos
{
	t_philo	*top;
	t_philo	*bottom;
}	t_philos;

int	parse_args(t_args *args, int argc, char *argv[]);

#endif
