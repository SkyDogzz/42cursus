/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:44:35 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/18 13:35:50 by marvin           ###   ########.fr       */
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

size_t	ft_getsizeb(unsigned int u, struct s_option options)
{
	size_t	len;
	
	if (options.precision < 0)
		len = options.width - ft_countcharu(u);
	else {
		len = options.precision - ft_countcharu(u);
	}
	return (len);
}

void	ft_putupadded(unsigned int u, int fd, int count, char c)
{
	ft_addchar(c, fd, count);
	ft_putu_fd(u, fd);
}

size_t	ft_putuoptions_fd(unsigned int u, int fd, struct s_option options)
{
	size_t	len;
	int		padded;

	len = ft_countcharu(u);
	padded = ft_getsizeb(u, options);
	if (ft_getflag(options.flag, '-'))
	{
		ft_putu_fd(u, fd);
		ft_addchar(' ', fd, options.width - len);
		return (ft_getmax(2, options.width, len));
	}
	else if (ft_getflag(options.flag, '0'))
	{
		ft_addchar('0', fd, options.width - len);
		ft_putu_fd(u, fd);
	}
	else if (ft_getflag(options.flag, '0') || options.precision >= 0)
	{
		ft_putupadded(u, fd, padded, '0');
	}
	else
	{
		ft_addchar(' ', fd, options.width - len);
		ft_putu_fd(u, fd);
	}
	return (ft_getmax(3, options.width, len, options.precision));
}
