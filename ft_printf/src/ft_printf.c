/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:38:49 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 18:08:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	ft_puthex_fd(int n, char spe, int fd)
{
	char	num;

	if (n / 16 < 0 && n / 16 > -16)
		write(1, "-", 1);
	if (n / 16 > 0 | n / 16 < 0)
	{
		ft_puthex_fd(n / 16, fd, spe);
	}
	num = n % 16;
	if (num < 0)
		num *= -1;
	if (num <= 9)
		num += '0';
	else
	{
		if (spe == 'x')
			num += 'a' - 10;
		else
		{
			num += 'A' - 10;
		}
	}
	write(fd, &num, 1);
}

void	ft_print_with_option(struct s_option options, ...)
{
	va_list	ap;

	va_start(ap, options);
	if (options.specifier == 'd' || options.specifier == 'i')
		ft_putnbr_fd_options((int) va_arg(ap, int), 1, options);
	else if (options.specifier == 'c')
		ft_putchar_fd_options((char) va_arg(ap, int), 1, options);
	else if (options.specifier == 's')
		ft_putstr_fd_options((char *) va_arg(ap, char *), 1, options);
	else if (options.specifier == 'p')
		ft_putptr_fd_options((void *) va_arg(ap, void *), 1, options);
	else if (options.specifier == 'u')
		ft_putunbr_fd_options((unsigned int) va_arg(ap, int), 1, options);
	else if (options.specifier == 'x' || options.specifier == 'X')
		ft_puthex_fd_options((int) va_arg(ap, int), 1, options);
	else if (options.specifier == '%')
		write(STDIN_FILENO, "%", 1);
	va_end(ap);
}

int	ft_printf(const char *s, ...)
{
	va_list			ap;
	struct s_option	*options;

	options = (struct s_option *)malloc(sizeof(struct s_option));
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
		{
			s = ft_parse_first(options, (char *)s);
			s = ft_parse_second(options, (char *)s);
			options->specifier = 0;
			if (ft_isspecifier(*s))
				options->specifier = *s;
			else
				ft_putstr_fd("Specifier not known", STDERR_FILENO);
			ft_print_with_option(*options, va_arg(ap, void *));
		}
		else
			write(STDOUT_FILENO, s, 1);
		s++;
	}
	va_end(ap);
	return (0);
}
