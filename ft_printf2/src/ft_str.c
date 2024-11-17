/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:42:04 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/17 15:43:57 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putstroptions_fd(const char *s, int fd)
{
	if (s == NULL)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	ft_putstr_fd((char *)s, 1);
	return (ft_strlen(s));
}
