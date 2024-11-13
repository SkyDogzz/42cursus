/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:00:58 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 16:43:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_isflag(char c)
{
	char	*set;

	set = (char *)malloc(sizeof(char) * 6);
	ft_strlcpy(set, "-+ 0#", 5);
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

void	ft_store_flag(int *flag, char c)
{
	int		pos;
	char	*set;

	set = (char *)malloc(sizeof(char) * 6);
	ft_strlcpy(set, "-+ 0#", 5);
	pos = 0;
	while (set[pos])
	{
		if (set[pos] == c)
		{
			if (*flag & (1 << pos))
				return ;
			*flag += (1 << pos);
			return ;
		}
		pos++;
	}
}

int	ft_isspecifier(char c)
{
	char	*set;

	set = (char *)malloc(sizeof(char) * 10);
	ft_strlcpy(set, "cspdiuxX%", 10);
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

enum a_bool	ft_getflag(int flag, char c)
{
	int		pos;
	char	*set;

	set = (char *)malloc(sizeof(char) * 6);
	ft_strlcpy(set, "-+ 0#", 5);
	pos = 0;
	while (set[pos])
	{
		if (set[pos] == c)
		{
			if (flag & 1 << pos)
				return (TRUE);
			else
				return (FALSE);
		}
		pos++;
	}
	return (FALSE);
}

void	ft_store_int(int *len, char c)
{
	*len *= 10;
	*len += c - '0';
}
