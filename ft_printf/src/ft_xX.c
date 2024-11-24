/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xX.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:09:32 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/24 16:06:39 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_count_hex_digits(unsigned int x)
{
	int	len;

	if (x == 0)
		return (1);
	len = 0;
	while (x)
	{
		x /= 16;
		len++;
	}
	return (len);
}

static void	ft_put_hex_fd(unsigned int x, int uppercase, int fd)
{
	char	hex_digit;

	if (x / 16 > 0)
		ft_put_hex_fd(x / 16, uppercase, fd);
	hex_digit = x % 16;
	if (hex_digit < 10)
	{
		hex_digit += '0';
	}
	else
	{
		if (uppercase)
			hex_digit += 'A' - 10;
		else
			hex_digit += 'a' - 10;
	}
	ft_putchar_fd(hex_digit, fd);
}

static void	ft_compute_caracs_hex(t_carac *caracs, t_option *options,
	unsigned int x)
{
	caracs->sign_char = '\0';
	if (x == 0 && options->precision == 0)
		caracs->size = 0;
	else
		caracs->size = ft_count_hex_digits(x);
	if (options->precision > caracs->size)
		caracs->zeros = options->precision - caracs->size;
	else
		caracs->zeros = 0;
	if (options->sharp && x != 0)
	{
		if (options->specifier == 'X')
			ft_strlcpy(caracs->prefix, "0X", 3);
		else
			ft_strlcpy(caracs->prefix, "0x", 3);
	}
	else
		caracs->prefix[0] = '\0';
	caracs->total_length = caracs->size + caracs->zeros
		+ ft_strlen(caracs->prefix);
	caracs->pad = options->width - caracs->total_length;
	if (caracs->pad < 0)
		caracs->pad = 0;
	caracs->padleft = options->minus;
}

int	ft_putxoptions_fd(unsigned int x, struct s_option options, int fd)
{
	t_carac	caracs;
	int		uppercase;
	int		pad_with_zero;

	ft_compute_caracs_hex(&caracs, &options, x);
	uppercase = (options.specifier == 'X');
	pad_with_zero = (options.zero && options.precision < 0 && !options.minus);
	if (!caracs.padleft && !pad_with_zero)
		ft_addchar(caracs.pad, 0);
	if (caracs.prefix[0] != '\0')
		ft_putstr_fd(caracs.prefix, fd);
	if (!caracs.padleft && pad_with_zero)
		ft_addchar(caracs.pad, 1);
	ft_addchar(caracs.zeros, 1);
	if (caracs.size > 0)
		ft_put_hex_fd(x, uppercase, fd);
	if (caracs.padleft)
		ft_addchar(caracs.pad, 0);
	return (caracs.total_length + caracs.pad);
}
