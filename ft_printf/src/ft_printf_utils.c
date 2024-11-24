/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:25:07 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/24 16:05:07 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_printwithoptions(int fd, struct s_option options, ...)
{
	va_list	ap;
	size_t	len;

	va_start(ap, options);
	len = 0;
	if (options.specifier == 'c')
		len += ft_putcoptions_fd((const char)va_arg(ap, int), options, fd);
	else if (options.specifier == 's')
		len += ft_putsoptions_fd((const char *)va_arg(ap, char *), options, fd);
	else if (options.specifier == 'p')
		len += ft_putpoptions_fd(va_arg(ap, unsigned long long), options, fd);
	else if (options.specifier == 'd' || options.specifier == 'i')
		len += ft_putdioptions_fd((int)va_arg(ap, int), options, fd);
	else if (options.specifier == 'u')
		len += ft_putuoptions_fd(va_arg(ap, unsigned int), options, fd);
	else if (options.specifier == 'x' || options.specifier == 'X')
		len += ft_putxoptions_fd(va_arg(ap, unsigned int), options, fd);
	va_end(ap);
	return (len);
}

size_t	ft_handlespecifier(va_list ap, struct s_option *options, int fd)
{
	size_t	len;

	if (options->specifier == '%')
	{
		ft_putchar_fd('%', fd);
		len = 1;
	}
	else
		len = ft_printwithoptions(fd, *options, va_arg(ap, void *));
	return (len);
}
