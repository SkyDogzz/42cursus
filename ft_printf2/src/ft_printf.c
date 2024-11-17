/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:17:59 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/17 14:56:15 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

void	ft_initoptions(struct s_option *options)
{
	options->specifier = 0;
	options->flag = 0;
	options->width = 0;
	options->precision = 0;
	options->length = 0;
}

int	ft_isspecifier(const char c)
{
	char	*set;
	void	*start;

	set = ft_strdup(SPECIFIERS);
	start = set;
	while (*set)
	{
		if (c == *set)
		{
			free(start);
			return (1);
		}
		set++;
	}
	free(start);
	return (0);
}

int	ft_isflag(const char c)
{
	char	*set;
	void	*start;

	set = ft_strdup(FLAGS);
	start = set;
	while (*set)
	{
		if(c == *set)
		{
			free(start);
			return (1);
		}
		set++;
	}
	free(start);
	return (0);
}

void	ft_storeflag(const char c, int *flag)
{
	char	*set;
	int		pos;

	set = ft_strdup(FLAGS);
	while (set[pos])
	{
		if (c == set[pos])
		{
			if (!(*flag & (1 << pos)))
				*flag += (1 << pos);
			free(set - sizeof(char) * pos);
			return ;
		}
		pos++;
	}
}

void	ft_storeint(const char c, int *n)
{
	*n *= 10;
	*n += c - '0';
}

int	ft_storelength(const char *s, int *length)
{
	if (*s == 'l')
	{
		if (*(s + 1) == 'l')
		{
			*length = LONG_LONG;
			return (2);
		}
		*length = LONG;
		return (1);
	} else if (*s == 'h')
	{
		if (*(s + 1) == 'h')
		{
			*length = SHORT_SHORT;
			return (2);
		}
		*length = SHORT;
		return (1);
	}
	return (0);
}

int	ft_parseoptions(const char *fmt, struct s_option *options)
{
	size_t	len;

	len = 0;
	fmt++;
	while (ft_isflag(*fmt))
	{
		ft_storeflag(*fmt, &options->flag);
		fmt++;
		len++;
	}
	while (*fmt >= '0' && *fmt <= 9)
	{
		ft_storeint(*fmt, &options->width);
		fmt++;
	}
	if (*fmt == '.')
	{
		fmt++;
		while (*fmt >= '0' && *fmt <= 9)
		{
			ft_storeint(*fmt, &options->precision);
			fmt++;
		}
	}
	fmt += ft_storelength(fmt, &options->length);
	if (ft_isspecifier(*fmt))
	{
		options->specifier = *fmt;
		fmt++;
		len++;
	}
	return (len);
}

int	ft_putcharoptions_fd(const char c, int fd)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_putstroptions_fd(const char *s, int fd)
{
	ft_putstr_fd((char *)s, 1);
	return (ft_strlen(s));
}

void	ft_putp_fd(unsigned long long p, int fd, int big)
{
	char	digit;

	if (p / 16 > 0)
		ft_putp_fd(p / 16, fd, big);
	if (p % 16 <= 9)
		digit = (p % 16) + '0';
	else
	{
		if (big)
			digit = (p % 16) + 'A' - 10;
		else
			digit = (p % 16) + 'a' - 10;
	}
	ft_putchar_fd(digit, fd);
}

int	ft_countcharp(unsigned long long p)
{
	int	len;

	len = 0;
	while (p)
	{
		p /= 16;
		len++;
	}
	return (len);
}

int	ft_putpoptions_fd(unsigned long long p, int fd)
{
	int	len;
	if (p == 0)
	{
		ft_putstr_fd("(nil)", fd);
		return (5);
	}
	len	= ft_countcharp(p) + 2;
	ft_putstr_fd("0x", fd);
	ft_putp_fd(p, fd, 0);
	return (len);
}

int	ft_countcharint(int n)
{
	int	len;

	len = 0;

	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbroptions_fd(int n, int fd)
{
	int	len;

	len = ft_countcharint(n);
	ft_putnbr_fd(n, fd);
	return (len);
}

void	ft_putu_fd(unsigned int	u, int fd)
{
	char	digit;

	if (u / 10 > 0)
		ft_putu_fd(u / 10, fd);
	digit = (u % 10) + '0';
	ft_putchar_fd(digit, fd);
}

int	ft_countcharu(unsigned int u)
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

int	ft_putuoptions_fd(unsigned int u, int fd)
{
	int	len;

	len = ft_countcharu(u);
	ft_putu_fd(u, fd);
	return (len);
}

int	ft_countcharx(unsigned int hex)
{
	int	len;

	if (hex == 0)
		return (1);
	len = 0;
	while (hex)
	{
		hex /= 16;
		len++;
	}
	return (len);
}

void	ft_putx_fd(unsigned int hex, int fd, int big)
{
	char	digit;

	if (hex / 16 > 0)
		ft_putx_fd(hex / 16, fd, big);
	if (hex % 16 <= 9)
		digit = (hex % 16) + '0';
	else
	{
		if (big)
			digit = (hex % 16) + 'A' - 10;
		else
			digit = (hex % 16) + 'a' - 10;
	}
	ft_putchar_fd(digit, fd);
}

int	ft_puthexbroptions_fd(unsigned int hex, int fd, struct s_option options)
{
	int	len;

	len = ft_countcharx(hex);
	if (options.specifier == 'X')
		ft_putx_fd(hex, fd, 1);
	else
		ft_putx_fd(hex, fd, 0);
	return (len);
}

int	ft_printwithoptions(struct s_option options, ...)
{
	va_list	ap;
	size_t	len;

	va_start(ap, NULL);
	len = 0;
	if(options.specifier == '%')
		len += ft_putcharoptions_fd(options.specifier, 1);
	else if (options.specifier == 'c')
		len += ft_putcharoptions_fd((const char)va_arg(ap, int), 1);
	else if (options.specifier == 's')
		len += ft_putstroptions_fd((const char *)va_arg(ap, char *), 1);
	else if (options.specifier == 'p')
		len += ft_putpoptions_fd((unsigned long long)va_arg(ap, unsigned long long), 1);
	else if (options.specifier == 'd' || options.specifier == 'i')
		len += ft_putnbroptions_fd((int)va_arg(ap, int), 1);
	else if (options.specifier == 'u')
		len += ft_putuoptions_fd((unsigned int)va_arg(ap, unsigned int), 1);
	else if (options.specifier == 'x' || options.specifier == 'X')
		len += ft_puthexbroptions_fd((unsigned int)va_arg(ap, unsigned int), 1, options);
	va_end(ap);
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list			ap;
	size_t			len;
	struct s_option options;

	va_start(ap, fmt);
	ft_initoptions(&options);
	len = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt += ft_parseoptions(fmt, &options);
			len += ft_printwithoptions(options, va_arg(ap, void *));
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
