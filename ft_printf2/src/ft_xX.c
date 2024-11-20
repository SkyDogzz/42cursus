/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xX.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:09:32 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/20 18:56:56 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_countxchar(unsigned int x)
{
	int		len;

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

void	ft_putxnbr(unsigned int x, int maj)
{
	char	letter;

	if (x / 16 > 0)
		ft_putxnbr(x / 16, maj);
	if (x % 16 <= 9)
		letter = x % 16 + '0';
	else
		letter = x % 16 + 'a' - 10 - maj * 32;
	write(1, &letter, 1);
}

void	ft_putxnbr_lim(unsigned int x, int maj, int lim)
{
	char	letter;

	if (!lim)
		return ;
	if (x / 16 > 0)
		ft_putxnbr_lim(x / 16, maj, lim - 1);
	if (x % 16 <= 9)
		letter = x % 16 + '0';
	else
		letter = x % 16 + 'a' - 10 - maj * 32;
	write(1, &letter, 1);
}

int	ft_putxoptions_fd(unsigned int u, struct s_option options, int fd)
{
	struct s_carac	caracs;
	int				maj;

	ft_initcaracs(&caracs);
	caracs.size = ft_countxchar(u);
	caracs.pad = options.width - caracs.size;
	caracs.padleft = options.minus;
	maj = 0;
	maj = options.specifier == 'X';
	if (options.precision >= 0 && options.precision > caracs.size)
	{
		ft_addchar(options.precision - caracs.size, 1);
		if (options.sharp && u != 0)
		{
			if (maj)
				ft_putstr_fd("0X", 1);
			else
				ft_putstr_fd("0x", 1);
		}
		ft_putxnbr(u, maj);
		return (ft_getmax(3, caracs.size, options.width, options.precision));
	}
	if (caracs.padleft)
	{
		if (options.sharp && u != 0)
		{
			if (maj)
				ft_putstr_fd("0X", 1);
			else
				ft_putstr_fd("0x", 1);
		}
		ft_putxnbr(u, maj);
		ft_addchar(caracs.pad, options.zero);
	}
	else
	{
		if (options.sharp && u != 0)
		{
			if (maj)
				ft_putstr_fd("0X", 1);
			else
				ft_putstr_fd("0x", 1);
		}
		ft_addchar(caracs.pad, options.zero);
		ft_putxnbr(u, maj);
	}
	return (ft_getmax(2, caracs.size, options.width)
		+ (options.sharp && u != 0) * 2);
	(void) fd;
}
