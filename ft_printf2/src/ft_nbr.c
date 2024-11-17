/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:43:03 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/17 18:36:31 by skydogzz         ###   ########.fr       */
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

void	ft_putnbrpadded(int n, int fd, int count, char c)
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
	while (count--)
		ft_putchar_fd(c, 1);
	if (n / 10 != 0)
		ft_putnbr_fd(n / 10, fd);
	num = (n % 10) + '0';
	write(fd, &num, 1);
}

size_t	ft_putnbroptions_fd(int n, int fd, struct s_option options)
{
	int	len;

	len = ft_countcharint(n);
	if (!options.width || options.width <= len)
	{
		ft_putnbr_fd(n, fd);
		return (len);
	}
	if (ft_getflag(options.flag, '-'))
	{
		ft_putnbr_fd(n, fd);
		ft_addchar(' ', fd, options.width - len);
	}
	else if (ft_getflag(options.flag, '0'))
	{
		ft_putnbrpadded(n, fd, options.width - len, '0');
	}
	else
	{
		ft_addchar(' ', fd, options.width - len);
		ft_putnbr_fd(n, fd);
	}
	return (options.width);
}
