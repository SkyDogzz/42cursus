/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:35:42 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/04 14:56:25 by tstephan         ###   ########.fr       */
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
			color.r = wrapper->map->content[y][x].color & 0xff;
			color.g = (wrapper->map->content[y][x].color >> 8) & 0xff;
			color.b = (wrapper->map->content[y][x].color >> 16) & 0xff;
			colint = color.b + (color.r << 8) + (color.g << 16);
			wrapper->map->content[y][x].color = colint;
			y++;
		}
		x++;
	}
	mlx_clear_window(wrapper->data.mlx_ptr, wrapper->data.win_ptr);
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
			wrapper->map->content[pos.y][pos.x].color = pseudo;
			pos.y++;
		}
		pos.x++;
	}
	mlx_clear_window(wrapper->data.mlx_ptr, wrapper->data.win_ptr);
	display_map(wrapper);
}
