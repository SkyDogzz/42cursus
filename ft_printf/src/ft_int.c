/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:20:12 by marvin            #+#    #+#             */
/*   Updated: 2024/11/14 17:24:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_putnbr_fd_options(int n, int fd, struct s_option options)
{
	int			len;

	len = ft_countcharint(n);
	if (!options.width)
		ft_putnbr_fd(n, fd);
	else if (ft_getflag(options.flag, '-'))
	{
		ft_putnbr_fd(n, fd);
		ft_addchar(options.width - len, ' ', fd);
	}
	else if (ft_getflag(options.flag, '0') && !options.precision)
	{
		ft_addchar(options.width - len, '0', fd);
		ft_putnbr_fd(n, fd);
	}
	else
	{
		ft_addchar(options.width - len, ' ', fd);
		ft_putnbr_fd(n, fd);
	}
	if (options.width > len)
		return (options.width);
	return (len);
}

int	ft_putunbr_fd_options(unsigned int n, int fd, struct s_option options)
{
	int			len;

	len = ft_countcharint(n);
	if (!options.width)
		ft_putunbr_fd(n, fd);
	else if (ft_getflag(options.flag, '-'))
	{
		ft_putunbr_fd(n, fd);
		ft_addchar(options.width - len, ' ', fd);
	}
	else if (ft_getflag(options.flag, '0') && !options.precision)
	{
		ft_addchar(options.width - len, '0', fd);
		ft_putunbr_fd(n, fd);
	}
	else
	{
		ft_addchar(options.width - len, ' ', fd);
		ft_putunbr_fd(n, fd);
	}
	if (options.width > len)
		return (options.width);
	return (len);
}

int	ft_countcharint(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	char	num;

	if (n / 10 > 0 | n / 10 < 0)
	{
		ft_putunbr_fd(n / 10, fd);
	}
	num = n % 10;
	num += '0';
	write(fd, &num, 1);
}
