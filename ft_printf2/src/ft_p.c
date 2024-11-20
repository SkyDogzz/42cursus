/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:55:08 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/20 15:21:19 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_countcharull(unsigned long long p)
{
	int len;

	len = 0;
	while (p)
	{
		p /= 16;
		len++;
	}
	return (len);
}

static void	ft_putull_fd(unsigned long long p, int fd)
{
	char letter;

	if (p / 16 > 0)
		ft_putull_fd(p / 16, fd);
	if (p % 16 <= 9)
		letter = p % 16 + '0';
	else
		letter = p % 16 + 'a' - 10;
	write(fd, &letter, 1);
}

int	ft_putpoptions_fd(unsigned long long p, struct s_option options, int fd)
{
	struct s_carac caracs;

	caracs.padLeft = options.minus;
	if (p == 0)
	{
		caracs.pad = options.width - 5;
		ft_putstr_padded("(nil)", caracs.pad, caracs.padLeft);
		return (ft_getmax(2, 5, options.width));
	}
	caracs.size = ft_countcharull(p) + 2;
	caracs.pad = options.width - caracs.size;
	if (caracs.padLeft)
	{
		ft_putstr_fd("0x", fd);
		ft_putull_fd(p, fd);
		ft_addchar(caracs.pad, options.zero);
	}
	else
	{
		ft_addchar(caracs.pad, options.zero);
		ft_putstr_fd("0x", fd);
		ft_putull_fd(p, fd);
	}
	return (ft_getmax(2, caracs.size, options.width));
}
