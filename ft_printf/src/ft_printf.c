/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:38:49 by marvin            #+#    #+#             */
/*   Updated: 2024/11/14 18:14:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_print_with_option(struct s_option options, ...)
{
	int size;
	va_list	ap;

	va_start(ap, options);
	if (options.specifier == 'd' || options.specifier == 'i')
		size = ft_putnbr_fd_options((int) va_arg(ap, int), 1, options);
	else if (options.specifier == 'c')
		size = ft_putchar_fd_options((char) va_arg(ap, int), 1, options);
	else if (options.specifier == 's')
		size = ft_putstr_fd_options((char *) va_arg(ap, char *), 1, options);
	else if (options.specifier == 'p')
		size = ft_putptr_fd_options((void *) va_arg(ap, void *), 1, options);
	else if (options.specifier == 'u')
		size = ft_putunbr_fd_options((unsigned int) va_arg(ap, int), 1, options);
	else if (options.specifier == 'x' || options.specifier == 'X')
		size = ft_puthex_fd_options((unsigned int) va_arg(ap, int), 1, options);

	va_end(ap);
	return (size);
}

int	ft_printf(const char *s, ...)
{
	int				size;
	va_list			ap;
	struct s_option	*options;

	size = 0;
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
			if (options->specifier == '%')
			{
				write(STDIN_FILENO, "\%", 1);
				size += 1;
			}
			else
			size += ft_print_with_option(*options, va_arg(ap, void *));
		}
		else
	{
			write(STDOUT_FILENO, s, 1);
			size++;
		}
		s++;
	}
	free(options);
	va_end(ap);
	return (size);
}
