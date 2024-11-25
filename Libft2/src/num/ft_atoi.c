/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:32:30 by marvin            #+#    #+#             */
/*   Updated: 2024/11/25 02:24:14 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

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
