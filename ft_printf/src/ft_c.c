/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:13:36 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/22 18:19:29 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_compute_caracs_char(t_carac *caracs, t_option *options)
{
	caracs->size = 1;
	caracs->zeros = 0;
	caracs->sign_char = '\0';
	caracs->total_length = caracs->size;
	caracs->pad = options->width - caracs->total_length;
	if (caracs->pad < 0)
		caracs->pad = 0;
	caracs->padleft = options->minus;
}

int	ft_putcoptions_fd(const char c, struct s_option options, int fd)
{
	t_carac	caracs;

	ft_compute_caracs_char(&caracs, &options);
	if (caracs.padleft)
	{
		ft_putchar_fd(c, fd);
		ft_addchar(caracs.pad, options.zero);
	}
	else
	{
		ft_addchar(caracs.pad, options.zero);
		ft_putchar_fd(c, fd);
	}
	return (caracs.total_length + caracs.pad);
}
