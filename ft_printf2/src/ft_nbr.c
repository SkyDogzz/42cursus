/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:43:03 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/18 00:58:00 by skydogzz         ###   ########.fr       */
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
	else if (sign)
	{
		ft_putchar_fd('+', fd);
		count--;
	}
	while (count >= 0 && count--)
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
	else if (sign && n >= 0)
	{
		ft_putchar_fd('+', fd);
		ft_putnbr_fd(n, fd);
	}
}

size_t	ft_getsizea(int n, int precision)
{
	size_t len;

	len = precision - ft_countcharint(n);
	if (n < 0)
		len++;
	return (len);
}

size_t	ft_putnbroptions_fd(int n, int fd, struct s_option options)
{
	int	len;
	int	padded;

	len = ft_countcharint(n);
	padded = ft_getsizea(n, options.precision);
	if (ft_getflag(options.flag, ' '))
		if (n >= 0)
		{
			ft_putchar_fd(' ', fd);
			len--;
		}
	if (ft_getflag(options.flag, '-'))
	{
		ft_putnbrsign(n, fd, ft_getflag(options.flag, '+'));
		ft_addchar(' ', fd, options.width - len - ft_getflag(options.flag, '+'));
	}
	else if (ft_getflag(options.flag, '0') || options.precision >= 0)
	{
		ft_putnbrpadded(n, fd, padded, '0', ft_getflag(options.flag, '+'));
	}
	else
	{
		ft_addchar(' ', fd, options.width - len - ft_getflag(options.flag, '+'));
		ft_putnbrsign(n, fd, ft_getflag(options.flag, '+'));
	}
	return (ft_getmax(3, options.width, len, options.precision + 
				    ((n & (1 << (sizeof(int) * 8 - 1))) != 0)));
}
