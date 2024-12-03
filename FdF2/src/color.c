/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:35:42 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/03 23:01:10 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	change_all_color(t_wrapper *wrapper)
{
	t_color	color;
	int		colint;

	for (int x = 0; x < wrapper->map->dims.width; x++)
	{
		for (int y = 0; y < wrapper->map->dims.height; y++)
		{
			color.r = wrapper->map->content[y][x].color & 0xff;
			color.g = wrapper->map->content[y][x].color >> 8 & 0xff;
			color.b = wrapper->map->content[y][x].color >> 16 & 0xff;
			colint = color.b + (color.r << 8) + (color.g << 16);
			wrapper->map->content[y][x].color = colint;
		}
	}		
	mlx_clear_window(wrapper->data.mlx_ptr, wrapper->data.win_ptr);
	display_map(wrapper);
}

unsigned int	pseudo_random(unsigned int seed)
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
	int	pseudo;

	pseudo = SEED;
	for (int x = 0; x < wrapper->map->dims.width; x++)
	{
		for (int y = 0; y < wrapper->map->dims.height; y++)
		{
			pseudo = pseudo_random(pseudo);
			wrapper->map->content[y][x].color = pseudo;
		}
	}
	mlx_clear_window(wrapper->data.mlx_ptr, wrapper->data.win_ptr);
	display_map(wrapper);
}
