/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:41:56 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/21 02:33:03 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_addchar(int count, int zero)
{
	char	c;

	c = ' ';
	if (zero)
		c = '0';
	while (count-- > 0)
		ft_putchar_fd(c, 1);
}

int	ft_getmax(int count, ...)
{
	va_list	ap;
	int		max;
	int		act;

	if (count <= 0)
		return (0);
	va_start(ap, count);
	max = va_arg(ap, int);
	while (--count)
	{
		act = va_arg(ap, int);
		if (act > max)
			max = act;
	}
	va_end(ap);
	return (max);
}
