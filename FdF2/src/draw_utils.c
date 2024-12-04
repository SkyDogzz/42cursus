/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:27:23 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/04 15:42:07 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	display_map(t_wrapper *wrapper)
{
	t_2vec		start;
	int			x;
	int			y;

	x = -1;
	while (++x < wrapper->map->dims.width)
	{
		y = -1;
		while (++y < wrapper->map->dims.height)
		{
			start.x = wrapper->map->content[y][x].pos.x * wrapper->map->zoom
				+ WINDOW_WIDTH / 2 + wrapper->map->offset.x;
			start.y = wrapper->map->content[y][x].pos.y * wrapper->map->zoom
				+ WINDOW_HEIGHT / 2 + wrapper->map->offset.y;
			if (y < wrapper->map->dims.height - 1)
				draw_vertical_lines(wrapper, x, y, start);
			if (x < wrapper->map->dims.width - 1)
				draw_horizontal_lines(wrapper, x, y, start);
		}
	}
	draw_helper(wrapper);
	if (wrapper->menu)
		display_menu(wrapper);
}

void	draw_line(t_2vec start, t_2vec end, t_2color color, t_wrapper wrapper)
{
	t_2vec	d;
	t_2vec	s;
	t_2vec	e;
	double	line_length;
	int		pos;

	d.x = abs(end.x - start.x);
	d.y = -abs(end.y - start.y);
	s = get_step(start, end);
		e.x = d.x + d.y;
	line_length = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
	pos = 1;
	while (1)
	{
		mlx_pixel_put(wrapper.data.mlx_ptr, wrapper.data.win_ptr, start.x,
			start.y, get_color2(color, line_length, pos));
		if (start.x == end.x && start.y == end.y)
			break ;
		update_position(&start, &s, &e, &d);
		pos++;
	}
}

void	draw_vertical_lines(t_wrapper *wrapper, int x, int y, t_2vec start)
{
	t_2vec		end;
	t_2color	color;

	end.x = wrapper->map->content[y + 1][x].pos.x * wrapper->map->zoom
		+ WINDOW_WIDTH / 2 + wrapper->map->offset.x;
	end.y = wrapper->map->content[y + 1][x].pos.y * wrapper->map->zoom
		+ WINDOW_HEIGHT / 2 + wrapper->map->offset.y;
	color.start = wrapper->map->content[y][x].color;
	color.end = wrapper->map->content[y + 1][x].color;
	draw_line(start, end, color, *wrapper);
}

void	draw_horizontal_lines(t_wrapper *wrapper, int x, int y, t_2vec start)
{
	t_2vec		end;
	t_2color	color;

	end.x = wrapper->map->content[y][x + 1].pos.x * wrapper->map->zoom
		+ WINDOW_WIDTH / 2 + wrapper->map->offset.x;
	end.y = wrapper->map->content[y][x + 1].pos.y * wrapper->map->zoom
		+ WINDOW_HEIGHT / 2 + wrapper->map->offset.y;
	color.start = wrapper->map->content[y][x].color;
	color.end = wrapper->map->content[y][x + 1].color;
	draw_line(start, end, color, *wrapper);
}
