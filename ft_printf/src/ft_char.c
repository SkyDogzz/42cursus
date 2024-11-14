/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:12:32 by marvin            #+#    #+#             */
/*   Updated: 2024/11/14 13:18:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	ft_addchar(int n, char c, int fd)
{
	while (n-- > 0)
		write(fd, &c, 1);
}

void	ft_putchar_fd_options(char c, int fd, struct s_option options)
{
	int	len;

	len = 1;
	if (!options.width)
		ft_putchar_fd(c, fd);
	else if (ft_getflag(options.flag, '-'))
	{
		ft_putchar_fd(c, fd);
		ft_addchar(options.width - len, ' ', fd);
	}
	else if (ft_getflag(options.flag, '0') && !options.precision)
	{
		ft_addchar(options.width - len, '0', fd);
		ft_putchar_fd(c, fd);
	}
	else
	{
		ft_addchar(options.width - len, ' ', fd);
		ft_putchar_fd(c, fd);
	}
}
