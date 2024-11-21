/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:26:07 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/21 01:11:37 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_countdichar_abs(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	if (n >= 10)
		ft_putnbr_unsigned_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

int	ft_putdioptions_fd(int d, struct s_option options, int fd)
{
	char			sign_char;
	unsigned int	abs_d;
	int				num_digits;
	int				zeros;
	int				total_length;
	int				padding;

	sign_char = 0;
	zeros = 0;
	if (d == 0 && options.precision == 0)
	{
		ft_addchar(options.width, 0);
		return (options.width);
	}
	if (d < 0)
		sign_char = '-';
	else if (options.plus)
		sign_char = '+';
	else if (options.space)
		sign_char = ' ';
	if (d < 0)
		abs_d = -(unsigned int)d;
	else
		abs_d = (unsigned int)d;
	num_digits = ft_countdichar_abs(abs_d);
	if (options.precision >= 0)
	{
		options.zero = 0;
		zeros = options.precision - num_digits;
		if (zeros < 0)
			zeros = 0;
	}
	total_length = num_digits + zeros;
	if (sign_char != 0)
		total_length += 1;
	padding = options.width - total_length;
	if (padding < 0)
		padding = 0;
	if (options.minus)
	{
		if (sign_char != 0)
			ft_putchar_fd(sign_char, fd);
		ft_addchar(zeros, 1);
		ft_putnbr_unsigned_fd(abs_d, fd);
		ft_addchar(padding, 0);
	}
	else
	{
		if (options.zero)
		{
			if (sign_char != 0)
				ft_putchar_fd(sign_char, fd);
			ft_addchar(padding, 1);
		}
		else
		{
			ft_addchar(padding, 0);
			if (sign_char != 0)
				ft_putchar_fd(sign_char, fd);
		}
		ft_addchar(zeros, 1);
		ft_putnbr_unsigned_fd(abs_d, fd);
	}
	return (total_length + padding);
}
