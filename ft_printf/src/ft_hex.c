/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:09:12 by marvin            #+#    #+#             */
/*   Updated: 2024/11/14 16:34:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_countcharhex(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_puthex_fd_options(int n, int fd, struct s_option options)
{
	int	len;

	len = ft_countcharhex(n);
	if (!options.width)
		ft_puthex_fd(n, options.specifier, fd);
	else if (ft_getflag(options.flag, '-'))
	{
		ft_puthex_fd(n, options.specifier, fd);
		ft_addchar(options.width - len, ' ', fd);
	}
	else if (ft_getflag(options.flag, '0') && !options.precision)
	{
		ft_addchar(options.width - len, '0', fd);
		ft_puthex_fd(n, options.specifier, fd);
	}
	else
	{
		ft_addchar(options.width - len, ' ', fd);
		ft_puthex_fd(n, options.specifier, fd);
	}
	if (options.width > len)
		return (options.width);
	return (len);
}

void	ft_puthex_fd(int n, char spe, int fd)
{
	char	num;

	if (n / 16 > 0 | n / 16 < 0)
	{
		ft_puthex_fd(n / 16, spe, fd);
	}
	num = n % 16;
	if (num < 0)
		num *= -1;
	if (num <= 9)
		num += '0';
	else
	{
		if (spe == 'x')
			num += 'a' - 10;
		else
		{
			num += 'A' - 10;
		}
	}
	write(fd, &num, 1);
}
