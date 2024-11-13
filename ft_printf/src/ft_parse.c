/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:41:09 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 17:48:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

char	*ft_parse_first(struct s_option *options, char *s)
{
	s++;
	options->flag = 0;
	while (ft_isflag(*s))
	{
		ft_store_flag(&options->flag, *s);
		s++;
	}
	options->width = 0;
	while (*s >= '0' && *s <= '9')
	{
		ft_store_int(&options->width, *s);
		s++;
	}
	options->precision = 0;
	if (*s == '.')
	{
		s++;
		while (*s >= '0' && *s <= '9')
		{
			ft_store_int(&options->precision, *s);
			s++;
		}
	}
	return (s);
}

char	*ft_parse_second(struct s_option *options, char *s)
{
	options->length = 0;
	if (*s == 'h')
	{
		if (*(s + 1) == 'h')
		{
			options->length = SHORT_SHORT;
			s++;
		}
		else
			options->length = SHORT;
		s++;
	}
	else if (*s == 'l')
	{
		if (*(s + 1) == 'l')
		{
			options->length = LONG_LONG;
			s++;
		}
		else
			options->length = LONG;
		s++;
	}
	return (s);
}
