/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:55:08 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/24 16:07:03 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_count_hex_digits_ull(unsigned long long p)
{
	int	len;

	if (p == 0)
		return (1);
	len = 0;
	while (p)
	{
		p /= 16;
		len++;
	}
	return (len);
}

static void	ft_put_hex_ull_fd(unsigned long long p, int fd)
{
	char	hex_digit;

	if (p / 16 > 0)
		ft_put_hex_ull_fd(p / 16, fd);
	hex_digit = "0123456789abcdef"[p % 16];
	ft_putchar_fd(hex_digit, fd);
}

static void	ft_compute_caracs_pointer(t_carac *caracs, t_option *options,
	unsigned long long p)
{
	if (p == 0)
	{
		caracs->content = "(nil)";
		caracs->size = 5;
		caracs->prefix[0] = '\0';
	}
	else
	{
		caracs->size = ft_count_hex_digits_ull(p);
		ft_strlcpy(caracs->prefix, "0x", 3);
		caracs->content = NULL;
	}
	caracs->zeros = 0;
	caracs->total_length = caracs->size + ft_strlen(caracs->prefix);
	caracs->pad = options->width - caracs->total_length;
	if (caracs->pad < 0)
		caracs->pad = 0;
	caracs->padleft = options->minus;
}

static void	ft_print_pointer_content(t_carac *caracs, unsigned long long p,
	int fd)
{
	if (caracs->content)
		ft_putstr_fd(caracs->content, fd);
	else
	{
		ft_putstr_fd(caracs->prefix, fd);
		ft_put_hex_ull_fd(p, fd);
	}
}

int	ft_putpoptions_fd(unsigned long long p, struct s_option options, int fd)
{
	t_carac	caracs;

	ft_compute_caracs_pointer(&caracs, &options, p);
	if (caracs.padleft)
	{
		ft_print_pointer_content(&caracs, p, fd);
		ft_addchar(caracs.pad, options.zero);
	}
	else
	{
		ft_addchar(caracs.pad, options.zero);
		ft_print_pointer_content(&caracs, p, fd);
	}
	return (caracs.total_length + caracs.pad);
}
