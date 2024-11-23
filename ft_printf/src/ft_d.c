/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:26:07 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/23 18:09:14 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_count_digits(int n)
{
	int				len;
	unsigned int	abs_n;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		abs_n = -n;
	else
		abs_n = n;
	while (abs_n)
	{
		abs_n /= 10;
		len++;
	}
	return (len);
}

static void	ft_put_unsigned_fd(unsigned int n, int fd)
{
	if (n >= 10)
		ft_put_unsigned_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

static void	ft_compute_caracs_int(t_carac *caracs, t_option *options, int n)
{
	if (n == 0 && options->precision == 0)
		caracs->size = 0;
	else
		caracs->size = ft_count_digits(n);
	if (n < 0)
		caracs->sign_char = '-';
	else if (options->plus)
		caracs->sign_char = '+';
	else if (options->space)
		caracs->sign_char = ' ';
	else
		caracs->sign_char = '\0';
	if (options->precision > caracs->size)
		caracs->zeros = options->precision - caracs->size;
	else
		caracs->zeros = 0;
	if (caracs->sign_char)
		caracs->total_length = caracs->size + caracs->zeros + 1;
	else
		caracs->total_length = caracs->size + caracs->zeros;
	caracs->pad = options->width - caracs->total_length;
	if (caracs->pad < 0)
		caracs->pad = 0;
	caracs->padleft = options->minus;
}

int	ft_putdioptions_fd(int n, struct s_option options, int fd)
{
	t_carac			caracs;
	unsigned int	abs_n;
	int				pad_with_zero;

	ft_compute_caracs_int(&caracs, &options, n);
	abs_n = n;
	if (n < 0)
		abs_n = -n;
	pad_with_zero = (options.zero && options.precision < 0 && !options.minus);
	if (!caracs.padleft && !pad_with_zero)
		ft_addchar(caracs.pad, 0);
	if (caracs.sign_char)
		ft_putchar_fd(caracs.sign_char, fd);
	if (!caracs.padleft && pad_with_zero)
		ft_addchar(caracs.pad, 1);
	ft_addchar(caracs.zeros, 1);
	if (caracs.size > 0)
		ft_put_unsigned_fd(abs_n, fd);
	if (caracs.padleft)
		ft_addchar(caracs.pad, 0);
	return (caracs.total_length + caracs.pad);
}
