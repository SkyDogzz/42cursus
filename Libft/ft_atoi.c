/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:32:30 by marvin            #+#    #+#             */
/*   Updated: 2024/11/20 23:06:56 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\n'
		|| c == '\v' || c == '\f');
}

int	ft_atoi(const char *s)
{
	int	sign;
	int	nb;

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
