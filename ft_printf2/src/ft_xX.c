/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xX.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:09:32 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/21 01:09:01 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_countxchar(unsigned int x)
{
	int	len;

	if (x == 0)
		return (1);
	len = 0;
	while (x > 0)
	{
		x /= 16;
		len++;
	}
	return (len);
}

void	ft_putxnbr_fd(unsigned int x, int maj, int fd)
{
	char	letter;

	if (x / 16 > 0)
		ft_putxnbr_fd(x / 16, maj, fd);
	if (x % 16 <= 9)
	{
		letter = x % 16 + '0';
	}
	else
	{
		if (maj)
			letter = x % 16 + 'A' - 10;
		else
			letter = x % 16 + 'a' - 10;
	}
	write(fd, &letter, 1);
}

int	ft_putxoptions_fd(unsigned int x, struct s_option options, int fd)
{
	struct s_carac	caracs;
	int				maj;
	int				result;

	ft_initcaracs(&caracs);
	if (x == 0 && options.precision == 0)
		caracs.size = 0;
	else
		caracs.size = ft_countxchar(x);
	caracs.pad = options.width - ft_getmax(2, caracs.size, options.precision);
	if (options.sharp && x != 0)
		caracs.pad -= 2;
	if (caracs.pad < 0)
		caracs.pad = 0;
	caracs.padleft = options.minus;
	maj = (options.specifier == 'X');
	if (!caracs.padleft)
	{
		if (!options.zero || options.precision >= 0)
			ft_addchar(caracs.pad, 0);
	}
	if (options.sharp && x != 0)
	{
		if (maj)
			ft_putstr_fd("0X", fd);
		else
			ft_putstr_fd("0x", fd);
	}
	if (options.precision > caracs.size)
		ft_addchar(options.precision - caracs.size, 1);
	if (!caracs.padleft && options.zero && options.precision < 0)
		ft_addchar(caracs.pad, 1);
	if (caracs.size > 0)
		ft_putxnbr_fd(x, maj, fd);
	if (caracs.padleft)
		ft_addchar(caracs.pad, 0);
	result = ft_getmax(3, caracs.size, options.width, options.precision);
	if (options.sharp && x != 0)
		result += 2;
	return (result);
}
