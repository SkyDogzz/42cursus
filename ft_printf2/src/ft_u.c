/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:44:35 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/17 18:07:39 by skydogzz         ###   ########.fr       */
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

size_t	ft_countcharu(unsigned int u)
{
	size_t	len;

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

size_t	ft_putuoptions_fd(unsigned int u, int fd, struct s_option options)
{
	size_t	len;

	len = ft_countcharu(u);
	if (!options.width || options.width <= len)
	{
		ft_putu_fd(u, fd);
		return (len);
	}
	if (ft_getflag(options.flag, '-'))
	{
		ft_putu_fd(u, fd);
		ft_addchar(' ', fd, options.width - len);
	}
	else
	{
		ft_addchar(' ', fd, options.width - len);
		ft_putu_fd(u, fd);
	}
	return (options.width);
}
