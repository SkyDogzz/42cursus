/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 02:17:59 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/04 14:29:35 by tstephan         ###   ########.fr       */
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

int	get_color2(t_2color color, double line_length, int pos)
{
	return (colormid(color, line_length + 2, pos));
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

void	display_menu(t_wrapper *wrapper)
{
	int		y;
	int		c;
	void	*m;
	void	*w;

	y = 5;
	m = wrapper->data.mlx_ptr;
	w = wrapper->data.win_ptr;
	c = 0xFFFFFF;
	mlx_string_put(m, w, 20, y += 15, c, "Keybinds :");
	mlx_string_put(m, w, 20, y += 15, c, "x to rotate around x axis");
	mlx_string_put(m, w, 20, y += 15, c, "y to rotate around y axis");
	mlx_string_put(m, w, 20, y += 15, c, "z to rotate around z axis");
	mlx_string_put(m, w, 20, y += 15, c, "arrows to translate");
	mlx_string_put(m, w, 20, y += 15, c, "page_up to zoom in");
	mlx_string_put(m, w, 20, y += 15, c, "page_down to zoom out");
	mlx_string_put(m, w, 20, y += 15, c, "j to increase height multiplier");
	mlx_string_put(m, w, 20, y += 15, c, "k to decrease height multiplier");
	mlx_string_put(m, w, 20, y += 15, c, "w to reset map");
	mlx_string_put(m, w, 20, y += 15, c, "space to toggle menu");
	mlx_string_put(m, w, 20, y += 15, c, "c to bitwise color");
	mlx_string_put(m, w, 20, y += 15, c, "r to randomise (seeded) color");
	mlx_string_put(m, w, 20, y += 15, c, "h to toggle helpers");
	mlx_string_put(m, w, 20, y += 15, c, "esc to quit");
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
