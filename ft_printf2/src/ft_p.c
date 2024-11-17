/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:39:27 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/17 15:40:29 by skydogzz         ###   ########.fr       */
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

int	ft_countcharp(unsigned long long p)
{
	int	len;

	len = 0;
	while (p)
	{
		p /= 16;
		len++;
	}
	return (len);
}

int	ft_putpoptions_fd(unsigned long long p, int fd)
{
	int	len;

	if (p == 0)
	{
		ft_putstr_fd("(nil)", fd);
		return (5);
	}
	len = ft_countcharp(p) + 2;
	ft_putstr_fd("0x", fd);
	ft_putp_fd(p, fd, 0);
	return (len);
}
