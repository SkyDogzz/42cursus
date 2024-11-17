/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:44:35 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/17 15:44:51 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putu_fd(unsigned int u, int fd)
{
	char	digit;

	if (u / 10 > 0)
		ft_putu_fd(u / 10, fd);
	digit = (u % 10) + '0';
	ft_putchar_fd(digit, fd);
}

int	ft_countcharu(unsigned int u)
{
	int	len;

	if (u == 0)
		return (1);
	len = 0;
	while (u)
	{
		u /= 10;
		len++;
	}
	return (len);
}

int	ft_putuoptions_fd(unsigned int u, int fd)
{
	int	len;

	len = ft_countcharu(u);
	ft_putu_fd(u, fd);
	return (len);
}
