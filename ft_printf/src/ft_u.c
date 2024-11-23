/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:45:37 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/23 18:09:29 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_count_unsigned_digits(unsigned int u)
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

static void	ft_put_unsigned_fd(unsigned int u, int fd)
{
	if (u >= 10)
		ft_put_unsigned_fd(u / 10, fd);
	ft_putchar_fd((u % 10) + '0', fd);
}

static void	ft_compute_caracs_unsigned(t_carac *caracs, t_option *options,
	unsigned int u)
{
	caracs->sign_char = '\0';
	if (u == 0 && options->precision == 0)
		caracs->size = 0;
	else
		caracs->size = ft_count_unsigned_digits(u);
	if (options->precision > caracs->size)
		caracs->zeros = options->precision - caracs->size;
	else
		caracs->zeros = 0;
	caracs->total_length = caracs->size + caracs->zeros;
	caracs->pad = options->width - caracs->total_length;
	if (caracs->pad < 0)
		caracs->pad = 0;
	caracs->padleft = options->minus;
}

int	ft_putuoptions_fd(unsigned int u, struct s_option options, int fd)
{
	t_carac	caracs;
	int		pad_with_zero;

	ft_compute_caracs_unsigned(&caracs, &options, u);
	pad_with_zero = (options.zero && options.precision < 0 && !options.minus);
	if (!caracs.padleft && !pad_with_zero)
		ft_addchar(caracs.pad, 0);
	if (caracs.sign_char)
		ft_putchar_fd(caracs.sign_char, fd);
	if (!caracs.padleft && pad_with_zero)
		ft_addchar(caracs.pad, 1);
	ft_addchar(caracs.zeros, 1);
	if (caracs.size > 0)
		ft_put_unsigned_fd(u, fd);
	if (caracs.padleft)
		ft_addchar(caracs.pad, 0);
	return (caracs.total_length + caracs.pad);
}
