/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:09:46 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/23 17:53:29 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	change_all_color(t_wrapper *wrapper)
{
	t_color	color;
	int		colint;
	int		x;
	int		y;

	x = 0;
	while (x < wrapper->map->dims.width)
	{
		y = 0;
		while (y < wrapper->map->dims.height)
		{
			color.r = wrapper->map->content[y * wrapper->map->dims.width
				+ x].color & 0xff;
			color.g = (wrapper->map->content[y * wrapper->map->dims.width
					+ x].color >> 8) & 0xff;
			color.b = (wrapper->map->content[y * wrapper->map->dims.width
					+ x].color >> 16) & 0xff;
			colint = color.b + (color.r << 8) + (color.g << 16);
			wrapper->map->content[y * wrapper->map->dims.width + x].color
				= colint;
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
	m = 1 << 31;
	seed = (a * seed + c) % m;
	return (seed);
}

int	colormid(t_2color color, int total, int act)
{
	t_color	start;
	t_color	end;
	t_color	mid;

	if (total <= 1)
		return (color.start);
	start.r = (color.start >> 16) & 0xFF;
	start.g = (color.start >> 8) & 0xFF;
	start.b = color.start & 0xFF;
	end.r = (color.end >> 16) & 0xFF;
	end.g = (color.end >> 8) & 0xFF;
	end.b = color.end & 0xFF;
	mid.r = start.r + ((end.r - start.r) * act) / (total - 1);
	mid.g = start.g + ((end.g - start.g) * act) / (total - 1);
	mid.b = start.b + ((end.b - start.b) * act) / (total - 1);
	return ((mid.r << 16) | (mid.g << 8) | mid.b);
}

int	get_color2(t_2color color, double line_length, int pos)
{
	return (colormid(color, line_length + 2, pos));
}

void	randomize_color(t_wrapper *wrapper)
{
	int		pseudo;
	t_2vec	pos;

	pseudo = SEED;
	pos.x = 0;
	while (pos.x < wrapper->map->dims.width)
	{
		pos.y = 0;
		while (pos.y < wrapper->map->dims.height)
		{
			pseudo = pseudo_random(pseudo);
			wrapper->map->content[pos.y * wrapper->map->dims.width
				+ pos.x].color = pseudo;
			pos.y++;
		}
		pos.x++;
	}
	display_map(wrapper);
}
