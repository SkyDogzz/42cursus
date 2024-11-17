/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:39:27 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/17 19:40:43 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putp_fd(unsigned long long p, int fd, int big)
{
	char	digit;

	if (p / 16 > 0)
		ft_putp_fd(p / 16, fd, big);
	if (p % 16 <= 9)
		digit = (p % 16) + '0';
	else
	{
		if (big)
			digit = (p % 16) + 'A' - 10;
		else
			digit = (p % 16) + 'a' - 10;
	}
	ft_putchar_fd(digit, fd);
}

size_t	ft_countcharp(unsigned long long p)
{
	size_t	len;

	len = 0;
	while (p)
	{
		p /= 16;
		len++;
	}
	return (len);
}

size_t	ft_putpoptions_fd(unsigned long long p, int fd, struct s_option options)
{
	size_t	len;

	if (p == 0)
	{
		ft_putstr_fd("(nil)", fd);
		return (5);
	}
	if (!options.width || options.width <= len)
	{
		ft_putstr_fd("0x", fd);
		ft_putp_fd(p, fd, 0);
		return (len);
	}
	if (ft_getflag(options.flag, '-'))
	{
		ft_putstr_fd("0x", fd);
		ft_putp_fd(p, fd, 0);
		ft_addchar(' ', fd, options.width - len);
	}
	else
	{
		ft_addchar(' ', fd, options.width - len);
		ft_putstr_fd("0x", fd);
		ft_putp_fd(p, fd, 0);
	}
	return (options.width);
}
