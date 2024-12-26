/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:00:00 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/26 10:35:07 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	change_all_color(t_wrapper *wrapper)
{
	t_color	c;
	int		colint;
	int		x;
	int		y;
	int		i;

	x = 0;
	while (x < wrapper->map->dims.width)
	{
		y = 0;
		while (y < wrapper->map->dims.height)
		{
			i = y * wrapper->map->dims.width + x;
			c.r = wrapper->map->content[i].color & 0xff;
			c.g = (wrapper->map->content[i].color >> 8) & 0xff;
			c.b = (wrapper->map->content[i].color >> 16) & 0xff;
			colint = c.b + (c.r << 8) + (c.g << 16);
			wrapper->map->content[i].color = colint;
			y++;
		}
		x++;
	}
	display_map(wrapper);
}

int	pseudo_random(int seed)
{
	unsigned int	a;
	unsigned int	c;
	unsigned int	m;

	a = 1664525;
	c = 1013904223;
	m = INT_MIN;
	seed = (int)((a * seed + c) % m);
	return (seed);
}

int	colormid(t_2color color, int total, int act)
{
	t_color	s;
	t_color	e;
	t_color	m;

	if (total <= 1)
		return (color.start);
	s.r = (color.start >> 16) & 0xFF;
	s.g = (color.start >> 8) & 0xFF;
	s.b = color.start & 0xFF;
	e.r = (color.end >> 16) & 0xFF;
	e.g = (color.end >> 8) & 0xFF;
	e.b = color.end & 0xFF;
	m.r = s.r + ((e.r - s.r) * act) / (total - 1);
	m.g = s.g + ((e.g - s.g) * act) / (total - 1);
	m.b = s.b + ((e.b - s.b) * act) / (total - 1);
	return ((m.r << 16) | (m.g << 8) | m.b);
}

int	get_color2(t_2color color, double line_len, int pos)
{
	int	total;

	total = (int)line_len + 2;
	return (colormid(color, total, pos));
}

void	randomize_color(t_wrapper *wrapper)
{
	int		pseudo;
	t_2vec	p;
	int		i;

	pseudo = SEED;
	p.x = 0;
	while (p.x < wrapper->map->dims.width)
	{
		p.y = 0;
		while (p.y < wrapper->map->dims.height)
		{
			pseudo = pseudo_random(pseudo);
			i = p.y * wrapper->map->dims.width + p.x;
			wrapper->map->content[i].color = pseudo;
			p.y++;
		}
		p.x++;
	}
	display_map(wrapper);
}
