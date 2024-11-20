/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:13:36 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/20 13:54:42 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putcoptions_fd(const char c, struct s_option options, int fd)
{
	struct s_carac caracs;

	(void) options;
	ft_initcaracs(&caracs);
	caracs.size = 1;
	caracs.pad = options.width - caracs.size;
	caracs.padLeft = options.minus;
	if (caracs.padLeft)
	{
		ft_putchar_fd(c, fd);
		ft_addchar(caracs.pad, options.zero);
	}
	else
	{
		ft_addchar(caracs.pad, options.zero);
		ft_putchar_fd(c, fd);
	}
	return (ft_getmax(2, caracs.size, options.width));
}
