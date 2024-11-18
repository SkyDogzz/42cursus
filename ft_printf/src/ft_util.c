/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:44:50 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/18 16:53:40 by marvin           ###   ########.fr       */
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

void	ft_putcharmodif(unsigned int hex, int fd, int big, enum e_bool modif)
{
	if (modif && hex)
	{
		if (big)
			ft_putstr_fd("0X", fd);
		else
			ft_putstr_fd("0x", fd);
	}
	ft_puthex_fd(hex, fd, big);
}

void	ft_puthexpadded(unsigned int hex, int count, char c, int big)
{
	ft_addchar(c, 1, count);
	ft_puthex_fd(hex, 1, big);
}
