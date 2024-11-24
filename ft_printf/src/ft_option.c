/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:27:55 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/24 13:15:22 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_initoptions(struct s_option *options)
{
	options->specifier = 0;
	options->sharp = false;
	options->space = false;
	options->plus = false;
	options->minus = false;
	options->zero = false;
	options->width = 0;
	options->precision = -1;
	options->length = 0;
}

bool	ft_isspecifier(const char c)
{
	char	*set;
	void	*start;

	set = ft_strdup(SPECIFIERS);
	start = set;
	while (*set)
	{
		if (c == *set)
		{
			free(start);
			return (true);
		}
		set++;
	}
	free(start);
	return (false);
}

bool	ft_isflag(const char c)
{
	char	*set;
	void	*start;

	set = ft_strdup(FLAGS);
	start = set;
	while (*set)
	{
		if (c == *set)
		{
			free(start);
			return (true);
		}
		set++;
	}
	free(start);
	return (false);
}
