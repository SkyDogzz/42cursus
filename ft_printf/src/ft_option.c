/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:00:58 by marvin            #+#    #+#             */
/*   Updated: 2024/11/14 13:45:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_isflag(char c)
{
	char	*set;
	void	*start;

	set = ft_strdup(FLAGS);
	start = set;
	while (*set)
	{
		if (*set == c)
		{
			free(start);
			return (1);
		}
		set++;
	}
	free(start);
	return (0);
}

void	ft_store_flag(int *flag, char c)
{
	int		pos;
	char	*set;
	void	*start;

	set = ft_strdup(FLAGS);
	start = set;
	pos = 0;
	while (set[pos])
	{
		if (set[pos] == c)
		{
			if (!(*flag & (1 << pos)))
				*flag += (1 << pos);
			free(start);
			return ;
		}
		pos++;
	}
	free(start);
}

int	ft_isspecifier(char c)
{
	char	*set;
	void	*start;

	set = ft_strdup(SPECIFIERS);
	start = set;
	while (*set)
	{
		if (*set == c)
		{
			free(start);
			return (1);
		}
		set++;
	}
	free(start);
	return (0);
}

enum a_bool	ft_getflag(int flag, char c)
{
	int		pos;
	char	*set;
	void	*start;

	set = ft_strdup(FLAGS);
	start = set;
	pos = 0;
	while (set[pos])
	{
		if (set[pos] == c)
		{
			free(start);
			if (flag & 1 << pos)
				return (TRUE);
			else
				return (FALSE);
		}
		pos++;
	}
	free(start);
	return (FALSE);
}

void	ft_store_int(int *len, char c)
{
	*len *= 10;
	*len += c - '0';
}
