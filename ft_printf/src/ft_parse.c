/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:27:24 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/24 16:50:02 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_parse_flags(const char **fmt, struct s_option *options)
{
	size_t	len;

	len = 0;
	while (ft_isflag(**fmt))
	{
		ft_storeflag(**fmt, options);
		(*fmt)++;
		len++;
	}
	return (len);
}

size_t	ft_parse_width(const char **fmt, struct s_option *options)
{
	size_t	len;

	len = 0;
	while (**fmt >= '0' && **fmt <= '9')
	{
		ft_storeint(**fmt, &options->width);
		(*fmt)++;
		len++;
	}
	return (len);
}

size_t	ft_parse_precision(const char **fmt, struct s_option *options)
{
	size_t	len;

	len = 0;
	if (**fmt == '.')
	{
		(*fmt)++;
		len++;
		options->precision = 0;
		while (**fmt >= '0' && **fmt <= '9')
		{
			ft_storeint(**fmt, &options->precision);
			(*fmt)++;
			len++;
		}
	}
	return (len);
}

size_t	ft_parseoptions(const char *fmt, struct s_option *options)
{
	size_t	len;

	len = 0;
	fmt++;
	len += ft_parse_flags(&fmt, options);
	len += ft_parse_width(&fmt, options);
	len += ft_parse_precision(&fmt, options);
	len += ft_storelength(fmt, &options->length);
	if (ft_isspecifier(*fmt))
	{
		options->specifier = *fmt;
		len++;
	}
	return (len);
}
