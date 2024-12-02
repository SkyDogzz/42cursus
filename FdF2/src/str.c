/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 02:12:32 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/02 02:49:52 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	atoi_base(const char *s, const char *base, const char *base2)
{
	int	nbr;
	int	pos;
	int	flag;

	nbr = 0;
	while (*s)
	{
		pos = 0;
		flag = 0;
		while (base[pos] && base2[pos])
		{
			if (base[pos] == *s || base2[pos] == *s)
			{
				nbr *= ft_strlen(base);
				nbr += pos;
				flag = 1;
			}
			pos++;
		}
		if (flag == 0)
			return (nbr);
		s++;
	}
	return (nbr);
}

int	get_color(const char *s)
{
	int	color;

	while (ft_isdigit(*s))
		s++;
	color = 0;
	if (*s != ',')
		return (0xFFFFFF);
	color = atoi_base((s + 3), "0123456789abcdef", "0123456789ABCDEF");
	return (color);
}

int	get_width(const char *line)
{
	int	width;

	width = 0;
	if (*line++ != ' ')
		width++;
	while (*line)
	{
		if (*line != ' ' && *(line - 1) == ' ' && *line != '\n')
			width++;
		line++;
	}
	return (width);
}
