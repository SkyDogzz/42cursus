/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:17:59 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/19 15:44:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_printwithoptions(struct s_option options, ...)
{
	va_list	ap;
	size_t	len;

	va_start(ap, options);
	len = 0;
	if (options.specifier == 'c')
		len += ft_putcharoptions_fd((const char)va_arg(ap, int), 1, options);
	else if (options.specifier == 's')
		len += ft_putstroptions_fd((const char *)va_arg(ap, char *), 1,
				options);
	else if (options.specifier == 'p')
		len += ft_putpoptions_fd((unsigned long long)va_arg(ap,
					unsigned long long), 1, options);
	else if (options.specifier == 'd' || options.specifier == 'i')
		len += ft_putnbroptions_fd((int)va_arg(ap, int), 1, options);
	else if (options.specifier == 'u')
		len += ft_putuoptions_fd((unsigned int)va_arg(ap, unsigned int), 1,
				options);
	else if (options.specifier == 'x' || options.specifier == 'X')
		len += ft_puthexbroptions_fd((unsigned int)va_arg(ap,
					unsigned int), 1, options);
	va_end(ap);
	return (len);
}

size_t	ft_handlespecifier(va_list ap,
							struct s_option *options)
{
	size_t	len;

	if (options->specifier == '%')
		len = ft_putcharoptions_fd(options->specifier, 1, *options);
	else
		len = ft_printwithoptions(*options, va_arg(ap, void *));
	return (len);
}

size_t	ft_printf(const char *fmt, ...)
{
	va_list			ap;
	size_t			len;
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
