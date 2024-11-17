/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:27:55 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/17 16:27:13 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_initoptions(struct s_option *options)
{
	options->specifier = 0;
	options->flag = 0;
	options->width = 0;
	options->precision = 0;
	options->length = 0;
}

t_bool	ft_isspecifier(const char c)
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
			return (TRUE);
		}
		set++;
	}
	free(start);
	return (FALSE);
}

t_bool	ft_isflag(const char c)
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
			return (TRUE);
		}
		set++;
	}
	free(start);
	return (FALSE);
}
