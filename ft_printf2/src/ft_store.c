/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:47:27 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/17 17:19:51 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_storeflag(const char c, int *flag)
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
			if (!(*flag & (1 << pos)))
				*flag += (1 << pos);
			free(start);
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

enum e_bool	ft_getflag(int flag, char c)
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
				return (TRUE);
			}
			free(start);
			return (FALSE);
		}
		pos++;
	}
	free(start);
	return (FALSE);
}
