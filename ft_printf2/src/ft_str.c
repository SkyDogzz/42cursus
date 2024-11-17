/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:42:04 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/17 17:37:43 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_putstroptions_fd(const char *s, int fd, struct s_option options)
{

	if (s == NULL)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	if (!options.width || options.width <= ft_strlen(s))
	{
		ft_putstr_fd((char *)s, fd);
		return (ft_strlen(s));
	}
	if (ft_getflag(options.flag, '-'))
	{
		ft_putstr_fd((char *)s, fd);
		ft_addchar(' ', fd, options.width - ft_strlen(s));
	}
	else
	{
		ft_addchar(' ', fd, options.width - ft_strlen(s));
		ft_putstr_fd((char *)s, fd);
	}
	return (options.width);
}
