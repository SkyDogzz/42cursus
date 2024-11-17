/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:31:39 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/17 17:37:23 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_addchar(const char c, int fd, int count)
{
	while (count--)
		ft_putchar_fd(c, fd);
}

size_t	ft_putcharoptions_fd(const char c, int fd, struct s_option options)
{
	if (!options.width || options.width <= 1)
	{
		ft_putchar_fd(c, fd);
		return (1);
	}
	if (ft_getflag(options.flag, '-'))
	{
		ft_putchar_fd(c, fd);
		ft_addchar(' ', fd, options.width - 1);
	}
	else
	{
		ft_addchar(' ', fd, options.width - 1);
		ft_putchar_fd(c, fd);
	}
	return (options.width);
}
