/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:31:39 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/17 22:49:12 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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
