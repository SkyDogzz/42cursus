/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 02:17:59 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/03 23:24:15 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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

void	draw_line(t_2vec start, t_2vec end, t_2color color, t_wrapper wrapper)
{
	int dx =  abs (end.x - start.x), sx = start.x < end.x ? 1 : -1;
	int dy = -abs (end.y - start.y), sy = start.y < end.y ? 1 : -1; 
	int err = dx + dy, e2;
	int pos = 1;

	while(pos++)
	{
		mlx_pixel_put(wrapper.data.mlx_ptr, wrapper.data.win_ptr, start.x, start.y,
				colormid(color, ZOOM + 2, pos));
		if (start.x == end.x && start.y == end.y) break;
		e2 = 2 * err;
		if (e2 >= dy) { err += dy; start.x += sx; }
		if (e2 <= dx) { err += dx; start.y += sy; }
	}
}

// void	display_map(t_mlx data, t_map map)
// {
// 	t_2vec pos;
// 	for (int x = 0; x < map.dims.width; x++)
// 		for (int y = 0; y < map.dims.height; y++)
// 		{
// 			pos.x = (( map.content[y][x].pos.x - (float) map.dims.width / 2) * MULT) + WINDOW_WIDTH / 2;
// 			pos.y = (( map.content[y][x].pos.y - (float) map.dims.height / 2) * MULT) + WINDOW_HEIGHT / 2;
// 			// pos.x = (( map.content[y][x].pos.x - (float) map.dims.width / 2)) + WINDOW_WIDTH / 2;
// 			// pos.y = (( map.content[y][x].pos.y - (float) map.dims.height / 2)) + WINDOW_HEIGHT / 2;
// 			mlx_pixel_put(data.mlx_ptr, data.win_ptr, pos.x, pos.y, map.content[y][x].color);
// 		}
// }

void	display_menu(t_wrapper *wrapper)
{
	int	y;

	y = 20;
	mlx_string_put(wrapper->data.mlx_ptr, wrapper->data.win_ptr, 20, 20, 0xFFFFFF, "Menu");
	mlx_string_put(wrapper->data.mlx_ptr, wrapper->data.win_ptr, 20, y += 15, 0xFFFFFF, "x to rotate around x axis");
	mlx_string_put(wrapper->data.mlx_ptr, wrapper->data.win_ptr, 20, y += 15, 0xFFFFFF, "y to rotate around y axis");
	mlx_string_put(wrapper->data.mlx_ptr, wrapper->data.win_ptr, 20, y += 15, 0xFFFFFF, "z to rotate around z axis");
	mlx_string_put(wrapper->data.mlx_ptr, wrapper->data.win_ptr, 20, y += 15, 0xFFFFFF, "page_up to zoom in");
	mlx_string_put(wrapper->data.mlx_ptr, wrapper->data.win_ptr, 20, y += 15, 0xFFFFFF, "page_down to zoom out");
	mlx_string_put(wrapper->data.mlx_ptr, wrapper->data.win_ptr, 20, y += 15, 0xFFFFFF, "space to toggle menu");
	mlx_string_put(wrapper->data.mlx_ptr, wrapper->data.win_ptr, 20, y += 15, 0xFFFFFF, "c to bitwise color");
	mlx_string_put(wrapper->data.mlx_ptr, wrapper->data.win_ptr, 20, y += 15, 0xFFFFFF, "r to randomise (seeded) color");
}

void	display_map(t_wrapper *wrapper)
{
	t_2vec		start;
	t_2vec		end;
	t_2color	color;

	for (int x = 0; x < wrapper->map->dims.width; x++)
	{
		for (int y = 0; y < wrapper->map->dims.height; y++)
		{
			start.x = wrapper->map->content[y][x].pos.x * wrapper->map->zoom + WINDOW_WIDTH / 2;
			start.y = wrapper->map->content[y][x].pos.y * wrapper->map->zoom + WINDOW_HEIGHT / 2;
			color.start = wrapper->map->content[y][x].color;
			if (y < wrapper->map->dims.height - 1)
			{
				end.x = wrapper->map->content[y + 1][x].pos.x * wrapper->map->zoom + WINDOW_WIDTH / 2;
				end.y = wrapper->map->content[y + 1][x].pos.y * wrapper->map->zoom + WINDOW_HEIGHT / 2;
				color.end = wrapper->map->content[y + 1][x].color;
				draw_line(start, end, color, *wrapper);
			}
			if (x < wrapper->map->dims.width - 1)
			{
				end.x = wrapper->map->content[y][x + 1].pos.x * wrapper->map->zoom + WINDOW_WIDTH / 2;
				end.y = wrapper->map->content[y][x + 1].pos.y * wrapper->map->zoom + WINDOW_HEIGHT / 2;
				color.end = wrapper->map->content[y][x + 1].color;
				draw_line(start, end, color, *wrapper);
			}
		}
	}
	if (wrapper->menu)
		display_menu(wrapper);
}
