/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:17:59 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/24 14:04:28 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	int				len;
	struct s_option	options;

	if (!fmt)
		return (-1);
	len = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			ft_initoptions(&options);
			fmt += ft_parseoptions(fmt, &options);
			len += ft_handlespecifier(ap, &options, fd);
		}
		else
		{
			ft_putchar_fd(*fmt, fd);
			len++;
		}
		fmt++;
	}
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, fmt);
	len = ft_vfprintf(1, fmt, ap);
	va_end(ap);
	return (len);
}

int	ft_dprintf(int fd, const char *fmt, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, fmt);
	len = ft_vfprintf(fd, fmt, ap);
	va_end(ap);
	return (len);
}

int	ft_vprintf(const char *fmt, va_list ap)
{
	return (ft_vfprintf(1, fmt, ap));
}
