/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:47:27 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/24 13:15:58 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_storeflag(const char c, struct s_option *options)
{
	if (c == '#')
		options->sharp = true;
	else if (c == ' ')
		options->space = true;
	else if (c == '+')
		options->plus = true;
	else if (c == '-')
		options->minus = true;
	else if (c == '0')
		options->zero = true;
}

void	ft_storeint(const char c, int *n)
{
	*n *= 10;
	*n += c - '0';
}

size_t	ft_storelength(const char *s, int *length)
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
	}
	else if (*s == 'h')
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

bool	ft_getflag(int flag, char c)
{
	char	*set;
	void	*start;
	int		pos;

	set = ft_strdup(FLAGS);
	start = set;
	pos = 0;
	while (set[pos])
	{
		if (c == set[pos])
		{
			if (flag & (1 << pos))
			{
				free(start);
				return (true);
			}
			free(start);
			return (false);
		}
		pos++;
	}
	free(start);
	return (false);
}
