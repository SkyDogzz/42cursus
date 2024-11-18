/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:42:04 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/18 13:47:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_strldup(const char *s, size_t l)
{
	int		pos;
	char	*dup;

	dup = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	pos = 0;
	while (*s && l)
	{
		*(dup + pos) = *s;
		s++;
		pos++;
		l--;
	}
	*(dup + pos) = 0;
	return (dup);
}

size_t	ft_getsize(int precision, int len)
{
	if (precision >= 0 && precision < len)
		return (precision);
	return (len);
}

size_t	ft_putstroptions_fd(const char *s, int fd, struct s_option options)
{
	char	*dup;
	int		size;

	if (s == NULL)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	size = ft_getsize(options.precision, ft_strlen(s));
	if (!options.width || options.width <= size)
	{
		dup = ft_strldup(s, size);
		ft_putstr_fd(dup, fd);
		free(dup);
		return (ft_getmax(2, size, options.width));
	}
	if (ft_getflag(options.flag, '-'))
	{
		dup = ft_strldup(s, options.precision);
		ft_putstr_fd(dup, fd);
		ft_addchar(' ', fd, options.width - size);
	}
	else
	{
		ft_addchar(' ', fd, options.width - size);
		dup = ft_strldup(s, options.precision);
		ft_putstr_fd(dup, fd);
	}
	free(dup);
	return (ft_getmax(2, size, options.width));
}
