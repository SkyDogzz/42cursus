/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 02:17:59 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/04 13:20:40 by tstephan         ###   ########.fr       */
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
	int dx, dy, sx, sy, err, e2, pos;
	double line_length;

	dx =  abs (end.x - start.x);
	sx = start.x < end.x ? 1 : -1;
	dy = -abs (end.y - start.y);
	sy = start.y < end.y ? 1 : -1; 
	line_length = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
	err = dx + dy;
	pos = 1;
	while(pos++)
	{
		mlx_pixel_put(wrapper.data.mlx_ptr, wrapper.data.win_ptr, start.x, start.y,
				colormid(color, line_length + 2, pos));
		if (start.x == end.x && start.y == end.y) break;
		e2 = 2 * err;
		if (e2 >= dy) { err += dy; start.x += sx; }
		if (e2 <= dx) { err += dx; start.y += sy; }
	}
}

void	display_menu(t_wrapper *wrapper)
{
	int	y;

	y = 20;
	mlx_string_put(wrapper->data.mlx_ptr, wrapper->data.win_ptr, 20, 20, 0xFFFFFF, "Menu");
	mlx_string_put(wrapper->data.mlx_ptr, wrapper->data.win_ptr, 20, y += 15, 0xFFFFFF, "x to rotate around x axis");
	mlx_string_put(wrapper->data.mlx_ptr, wrapper->data.win_ptr, 20, y += 15, 0xFFFFFF, "y to rotate around y axis");
	mlx_string_put(wrapper->data.mlx_ptr, wrapper->data.win_ptr, 20, y += 15, 0xFFFFFF, "z to rotate around z axis");
	mlx_string_put(wrapper->data.mlx_ptr, wrapper->data.win_ptr, 20, y += 15, 0xFFFFFF, "arrows to translate");
	mlx_string_put(wrapper->data.mlx_ptr, wrapper->data.win_ptr, 20, y += 15, 0xFFFFFF, "page_up to zoom in");
	mlx_string_put(wrapper->data.mlx_ptr, wrapper->data.win_ptr, 20, y += 15, 0xFFFFFF, "page_down to zoom out");
	mlx_string_put(wrapper->data.mlx_ptr, wrapper->data.win_ptr, 20, y += 15, 0xFFFFFF, "j to increase height multiplier");
	mlx_string_put(wrapper->data.mlx_ptr, wrapper->data.win_ptr, 20, y += 15, 0xFFFFFF, "k to decrease height multiplier");
	mlx_string_put(wrapper->data.mlx_ptr, wrapper->data.win_ptr, 20, y += 15, 0xFFFFFF, "w to reset map");
	mlx_string_put(wrapper->data.mlx_ptr, wrapper->data.win_ptr, 20, y += 15, 0xFFFFFF, "space to toggle menu");
	mlx_string_put(wrapper->data.mlx_ptr, wrapper->data.win_ptr, 20, y += 15, 0xFFFFFF, "c to bitwise color");
	mlx_string_put(wrapper->data.mlx_ptr, wrapper->data.win_ptr, 20, y += 15, 0xFFFFFF, "r to randomise (seeded) color");
	mlx_string_put(wrapper->data.mlx_ptr, wrapper->data.win_ptr, 20, y += 15, 0xFFFFFF, "h to toggle helpers");
	mlx_string_put(wrapper->data.mlx_ptr, wrapper->data.win_ptr, 20, y += 15, 0xFFFFFF, "esc to quit");
}

void	draw_helper(t_wrapper *wrapper)
{
	t_2vec		line[2];
	t_2color	color;

	if (!wrapper->map->helper)
		return ;
	color.start = 0xFF0000;
	color.end = 0x00FF00;
	line[0].x = WINDOW_WIDTH / 2;
	line[0].y = 0;
	line[1].x = WINDOW_WIDTH / 2;
	line[1].y = WINDOW_HEIGHT;
	draw_line(line[0], line[1], color, *wrapper);
	line[0].x = 0;
	line[0].y = WINDOW_HEIGHT / 2;
	line[1].x = WINDOW_WIDTH;
	line[1].y = WINDOW_HEIGHT / 2;
	draw_line(line[0], line[1], color, *wrapper);
}

void	display_map(t_wrapper *wrapper)
{
	t_2vec		start;
	t_2vec		end;
	t_2color	color;

	// printf("%f:%f ", wrapper->map->content[0][0].pos.x, wrapper->map->content[0][0].pos.y);
	// printf("%f:%f ", wrapper->map->content[0][wrapper->map->dims.width].pos.x, wrapper->map->content[0][wrapper->map->dims.width].pos.y);
	// printf("%f:%f ", wrapper->map->content[wrapper->map->dims.height][wrapper->map->dims.width].pos.x, wrapper->map->content[wrapper->map->dims.height][wrapper->map->dims.width].pos.y);
	// printf("%f:%f\n", wrapper->map->content[wrapper->map->dims.height][0].pos.x, wrapper->map->content[wrapper->map->dims.height][0].pos.y);
	for (int x = 0; x < wrapper->map->dims.width; x++)
	{
		for (int y = 0; y < wrapper->map->dims.height; y++)
		{
			start.x = wrapper->map->content[y][x].pos.x * wrapper->map->zoom + WINDOW_WIDTH / 2 + wrapper->map->offset.x;
			start.y = wrapper->map->content[y][x].pos.y * wrapper->map->zoom + WINDOW_HEIGHT / 2 + wrapper->map->offset.y;
			color.start = wrapper->map->content[y][x].color;
			if (y < wrapper->map->dims.height - 1)
			{
				end.x = wrapper->map->content[y + 1][x].pos.x * wrapper->map->zoom + WINDOW_WIDTH / 2 + wrapper->map->offset.x;
				end.y = wrapper->map->content[y + 1][x].pos.y * wrapper->map->zoom + WINDOW_HEIGHT / 2 + wrapper->map->offset.y;
				color.end = wrapper->map->content[y + 1][x].color;
				draw_line(start, end, color, *wrapper);
			}
			if (x < wrapper->map->dims.width - 1)
			{
				end.x = wrapper->map->content[y][x + 1].pos.x * wrapper->map->zoom + WINDOW_WIDTH / 2 + wrapper->map->offset.x;
				end.y = wrapper->map->content[y][x + 1].pos.y * wrapper->map->zoom + WINDOW_HEIGHT / 2 + wrapper->map->offset.y;
				color.end = wrapper->map->content[y][x + 1].color;
				draw_line(start, end, color, *wrapper);
			}
			usleep(10);
		}
	}
	draw_helper(wrapper);
	if (wrapper->menu)
		display_menu(wrapper);
}
