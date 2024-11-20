/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:45:37 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/20 18:57:31 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_countuchar(unsigned int u)
{
	int	len;

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

void	ft_putunbr(unsigned int u)
{
	char	letter;

	if (u / 10 > 0)
		ft_putunbr(u / 10);
	letter = u % 10 + '0';
	write(1, &letter, 1);
}

int	ft_putuoptions_fd(unsigned int u, struct s_option options, int fd)
{
	struct s_carac	caracs;

	ft_initcaracs(&caracs);
	caracs.size = ft_countuchar(u);
	caracs.pad = options.width - caracs.size;
	caracs.padleft = options.minus;
	if (options.precision >= 0 && options.precision > options.width)
	{
		ft_addchar(options.precision - caracs.size, 1);
	}
	if (caracs.padleft)
	{
		ft_putunbr(u);
		ft_addchar(caracs.pad, options.zero);
	}
	else
	{
		ft_addchar(caracs.pad, options.zero);
		ft_putunbr(u);
	}
	return (ft_getmax(3, caracs.size, options.width, options.precision));
	(void) fd;
}
