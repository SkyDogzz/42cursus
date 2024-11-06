/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:32:30 by marvin            #+#    #+#             */
/*   Updated: 2024/11/06 12:24:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\n'
		|| c == '\v' || c == '\f');
}

int	ft_atoi(const char *s)
{
	int	mult;
	int	nb;

	mult = 1;
	nb = 0;
	while (ft_isspace((int) *s))
		s++;
	if (*s == '-')
	{
		mult = -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		nb *= 10;
		nb += *s - '0';
		s++;
	}
	return (nb * mult);
}
