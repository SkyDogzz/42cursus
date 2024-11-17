/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:43:03 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/17 21:55:57 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_countcharint(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbrpadded(int n, int fd, int count, char c, enum e_bool sign)
{
	char	num;

	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == INT_MIN)
		{
			write(fd, "2", 1);
			n = 147483648;
		}
		else
		{
			n = -n;
		}
	}
	else
	{
		ft_putchar_fd('+', fd);
		count--;
	}
	while (count--)
		ft_putchar_fd(c, 1);
	if (n / 10 != 0)
		ft_putnbr_fd(n / 10, fd);
	num = (n % 10) + '0';
	write(fd, &num, 1);
}

void	ft_putnbrsign(int n, int fd, enum e_bool sign)
{
	if (!sign || n < 0)
		ft_putnbr_fd(n, fd);
	else if (n >= 0)
	{
		ft_putchar_fd('+', fd);
		ft_putnbr_fd(n, fd);
	}
}

size_t	ft_putnbroptions_fd(int n, int fd, struct s_option options)
{
	int	len;

	len = ft_countcharint(n);
	if (ft_getflag(options.flag, ' '))
		if (n >= 0)
		{
			ft_putchar_fd(' ', fd);
			len--;
		}
	if (!options.width || options.width <= len)
	{
		ft_putnbrsign(n, fd, ft_getflag(options.flag, '+'));
		if (n < 0)
			return (len);
		return (len + ft_getflag(options.flag, '+') + 2);
	}
	if (ft_getflag(options.flag, '-'))
	{
		ft_putnbrsign(n, fd, ft_getflag(options.flag, '+'));
		ft_addchar(' ', fd, options.width - len - ft_getflag(options.flag, '+'));
	}
	else if (ft_getflag(options.flag, '0'))
	{
		ft_putnbrpadded(n, fd, options.width - len, '0', ft_getflag(options.flag, '+'));
	}
	else
	{
		ft_addchar(' ', fd, options.width - len - ft_getflag(options.flag, '+'));
		ft_putnbrsign(n, fd, ft_getflag(options.flag, '+'));
	}
	return (options.width);
}
