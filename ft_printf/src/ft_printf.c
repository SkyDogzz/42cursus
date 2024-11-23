/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:17:59 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/23 16:52:18 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t	ft_printwithoptions(struct s_option options, ...)
{
	va_list	ap;
	size_t	len;

	va_start(ap, options);
	len = 0;
	if (options.specifier == 'c')
		len += ft_putcoptions_fd((const char)va_arg(ap, int), options, 1);
	else if (options.specifier == 's')
		len += ft_putsoptions_fd((const char *)va_arg(ap, char *), options, 1);
	else if (options.specifier == 'p')
		len += ft_putpoptions_fd(va_arg(ap, unsigned long long), options, 1);
	else if (options.specifier == 'd' || options.specifier == 'i')
		len += ft_putdioptions_fd((int)va_arg(ap, int), options, 1);
	else if (options.specifier == 'u')
		len += ft_putuoptions_fd(va_arg(ap, unsigned int), options, 1);
	else if (options.specifier == 'x' || options.specifier == 'X')
		len += ft_putxoptions_fd(va_arg(ap, unsigned int), options, 1);
	va_end(ap);
	return (len);
}

static size_t	ft_handlespecifier(va_list ap, struct s_option *options)
{
	size_t	len;

	if (options->specifier == '%')
		len = ft_putcoptions_fd(options->specifier, *options, 1);
	else
		len = ft_printwithoptions(*options, va_arg(ap, void *));
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list			ap;
	int				len;
	struct s_option	options;

	if (!fmt)
		return (-1);
	va_start(ap, fmt);
	len = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			ft_initoptions(&options);
			fmt += ft_parseoptions(fmt, &options);
			len += ft_handlespecifier(ap, &options);
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
			len++;
		}
		fmt++;
	}
	va_end(ap);
	return (len);
}
