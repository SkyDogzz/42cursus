/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:45:37 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/21 01:03:22 by skydogzz         ###   ########.fr       */
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

void	ft_putunbr_fd(unsigned int u, int fd)
{
	char	letter;

	if (u / 10 > 0)
		ft_putunbr_fd(u / 10, fd);
	letter = u % 10 + '0';
	write(fd, &letter, 1);
}

int	ft_putuoptions_fd(unsigned int u, struct s_option options, int fd)
{
	struct s_carac	caracs;

	ft_initcaracs(&caracs);
	if (u == 0 && options.precision == 0)
		caracs.size = 0;
	else
		caracs.size = ft_countuchar(u);
	caracs.pad = options.width - ft_getmax(2, caracs.size, options.precision);
	if (caracs.pad < 0)
		caracs.pad = 0;
	caracs.padleft = options.minus;
	if (!caracs.padleft && (!options.zero || options.precision >= 0))
		ft_addchar(caracs.pad, 0);
	if (options.precision > caracs.size)
		ft_addchar(options.precision - caracs.size, 1);
	if (!caracs.padleft && options.zero && options.precision < 0)
		ft_addchar(caracs.pad, 1);
	if (caracs.size > 0)
		ft_putunbr_fd(u, fd);
	if (caracs.padleft)
		ft_addchar(caracs.pad, 0);
	return (ft_getmax(3, caracs.size, options.width, options.precision));
}
