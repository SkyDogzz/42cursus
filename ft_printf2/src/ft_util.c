/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:44:50 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/17 23:08:16 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_addchar(const char c, int fd, int count)
{
	while (count >= 0 && count--)
		ft_putchar_fd(c, fd);
}

int	ft_getmax(int count, ...)
{
	int		act;
	int		max;
	va_list	ap;

	va_start(ap, count);
	max = va_arg(ap, int);
	while (--count)
	{
		act = va_arg(ap, int);
		if (act > max)
			max = act;
	}
	return (max);
}
