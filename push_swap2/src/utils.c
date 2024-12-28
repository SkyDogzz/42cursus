/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 06:07:52 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/28 06:07:52 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	ft_atol(const char *s)
{
	int		sign;
	long	nb;

	sign = 1;
	nb = 0;
	while (ft_isspace((int) *s))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit((int)*s))
	{
		nb = nb * 10 + (*s - '0');
		s++;
	}
	return (nb * sign);
}
