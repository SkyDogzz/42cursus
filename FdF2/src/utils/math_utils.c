/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:00:00 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/26 10:43:54 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	atoi_base(const char *s, const char *b1, const char *b2)
{
	int	nbr;
	int	pos;
	int	flag;

	nbr = 0;
	while (*s)
	{
		pos = 0;
		flag = 0;
		while (b1[pos] && b2[pos])
		{
			if (b1[pos] == *s || b2[pos] == *s)
			{
				nbr *= ft_strlen(b1);
				nbr += pos;
				flag = 1;
				break ;
			}
			pos++;
		}
		if (!flag)
			return (nbr);
		s++;
	}
	return (nbr);
}

t_2vec	get_step(t_2vec start, t_2vec end)
{
	t_2vec	s;

	s.x = 1;
	if (start.x > end.x)
		s.x = -1;
	s.y = 1;
	if (start.y > end.y)
		s.y = -1;
	return (s);
}

float	ft_min_float(float f1, float f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

void	update_position(t_2vec *start, const t_2vec *s, t_2vec *e,
					 const t_2vec *d)
{
	e->y = e->x * 2;
	if (e->y >= d->y)
	{
		e->x += d->y;
		start->x += s->x;
	}
	if (e->y <= d->x)
	{
		e->x += d->x;
		start->y += s->y;
	}
}

int	get_color(const char *s)
{
	while (*s && ft_isdigit(*s))
		s++;
	if (*s != ',')
		return (0xFFFFFF);
	return (atoi_base(s + 3, "0123456789abcdef", "0123456789ABCDEF"));
}
