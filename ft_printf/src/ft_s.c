/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:56:38 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/24 16:11:13 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_handle_null_string(t_carac *caracs, t_option *options)
{
	if (options->precision >= 0 && options->precision < 6)
	{
		caracs->content = "";
		caracs->size = 0;
	}
	else
	{
		caracs->content = "(null)";
		caracs->size = 6;
	}
}

static void	ft_compute_string_size(t_carac *caracs, t_option *options,
	const char *s)
{
	int	actual_length;

	caracs->content = (char *)s;
	actual_length = ft_strlen(caracs->content);
	if (options->precision >= 0 && options->precision < actual_length)
		caracs->size = options->precision;
	else
		caracs->size = actual_length;
}

static void	ft_compute_caracs_string(t_carac *caracs, t_option *options,
	const char *s)
{
	if (s == NULL)
		ft_handle_null_string(caracs, options);
	else
		ft_compute_string_size(caracs, options, s);
	caracs->zeros = 0;
	caracs->sign_char = '\0';
	caracs->total_length = caracs->size;
	caracs->pad = options->width - caracs->total_length;
	if (caracs->pad < 0)
		caracs->pad = 0;
	caracs->padleft = options->minus;
}

int	ft_putsoptions_fd(const char *s, struct s_option options, int fd)
{
	t_carac	caracs;

	ft_compute_caracs_string(&caracs, &options, s);
	if (!caracs.padleft)
		ft_addchar(caracs.pad, 0);
	if (caracs.size > 0)
		write(fd, caracs.content, caracs.size);
	if (caracs.padleft)
		ft_addchar(caracs.pad, 0);
	return (caracs.total_length + caracs.pad);
}
