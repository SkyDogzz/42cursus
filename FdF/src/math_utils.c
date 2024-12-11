/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:34:53 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/04 15:44:31 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_2vec	get_step(t_2vec start, t_2vec end)
{
	t_2vec	s;

	s.x = 1;
	if (start.x >= end.x)
		s.x = -1;
	s.y = 1;
	if (start.y >= end.y)
		s.y = -1;
	return (s);
}

float	min(float f1, float f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

void	update_position(t_2vec *start, t_2vec *s, t_2vec *e, t_2vec *d)
{
	e->y = 2 * e->x;
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

int	get_height(int fd)
{
	int		height;
	char	*line;

	height = 1;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	free(line);
	return (height);
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
