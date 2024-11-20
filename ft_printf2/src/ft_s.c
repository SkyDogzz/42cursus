/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:56:38 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/20 15:24:50 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putsoptions_fd(const char *s, struct s_option options, int fd)
{
	struct s_carac caracs;

	ft_initcaracs(&caracs);
	caracs.padLeft = options.minus;
	if (!s)
	{
		caracs.pad = options.width - 6;
		if (options.precision >= 0 && options.precision < 6)
		{
			write(1, s, options.precision);
			return (0);
		}
		ft_putstr_padded("(null)", caracs.pad, caracs.padLeft);
		return (ft_getmax(2, 6, options.width));
	}
	caracs.size = ft_strlen(s);
	caracs.pad = options.width - caracs.size;
	if (options.precision >= 0 && options.precision < caracs.size)
	{
		if (options.width > options.precision)
		{
			if (!caracs.padLeft)
				ft_addchar(options.width - options.precision, options.zero);
			write(1, s, options.precision);
			if (caracs.padLeft)
				ft_addchar(options.width - options.precision, options.zero);
		}
		else
			write(1, s, options.precision);
		return (ft_getmax(2, options.precision, options.width));
	}
	if (caracs.padLeft)
	{
		ft_putstr_fd((char *)s, fd);
		ft_addchar(caracs.pad, options.zero);
	}
	else
	{
		ft_addchar(caracs.pad, options.zero);
		ft_putstr_fd((char *)s, fd);
	}
	return (ft_getmax(2, caracs.size, options.width));
}
