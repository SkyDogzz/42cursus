/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 02:17:59 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/03 14:31:53 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

#define MULT 40



int	colormid(t_2color color, int total, int act)
{
	t_color start;
	t_color	end;
	t_color mid;

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


void	draw_line (t_2vec start, t_2vec end, t_2color color, t_wrapper wrapper)
{
	int dx =  abs (end.x - start.x), sx = start.x < end.x ? 1 : -1;
	int dy = -abs (end.y - start.y), sy = start.y < end.y ? 1 : -1; 
	int err = dx + dy, e2;
	int pos = 1;

	while(pos++){
		mlx_pixel_put(wrapper.data.mlx_ptr, wrapper.data.win_ptr, start.x, start.y,
				colormid(color, MULT + 2, pos));
		if (start.x == end.x && start.y == end.y) break;
		e2 = 2 * err;
		if (e2 >= dy) { err += dy; start.x += sx; }
		if (e2 <= dx) { err += dx; start.y += sy; }
	}
	(void) color;
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

void	display_map(t_mlx data, t_map map)
{
	t_wrapper	wrapper;
	t_2vec		start;
	t_2vec		end;
	t_2color	color;

	wrapper.map = &map;
	wrapper.data = data;
	for (int x = 0; x < map.dims.width; x++)
	{
		for (int y = 0; y < map.dims.height; y++)
		{
			start.x = map.content[y][x].pos.x * MULT + WINDOW_WIDTH / 2;
			start.y = map.content[y][x].pos.y * MULT + WINDOW_HEIGHT / 2;
			color.start = map.content[y][x].color;
			if (y < map.dims.height - 1)
			{
				end.x = map.content[y + 1][x].pos.x * MULT + WINDOW_WIDTH / 2;
				end.y = map.content[y + 1][x].pos.y * MULT + WINDOW_HEIGHT / 2;
				color.end = map.content[y + 1][x].color;
				draw_line(start, end, color, wrapper);
			}
			if (x < map.dims.width - 1)
			{
				end.x = map.content[y][x + 1].pos.x * MULT + WINDOW_WIDTH / 2;;
				end.y = map.content[y][x + 1].pos.y * MULT + WINDOW_HEIGHT / 2;
				color.end = map.content[y][x + 1].color;
				draw_line(start, end, color, wrapper);
			}
		}
	}
}
