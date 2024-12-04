/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:27:23 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/04 18:03:33 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	display_map(t_wrapper *wrap)
{
	t_2vec		start;
	t_2vec		pos;

	wrap->data.img.mlx_img = mlx_new_image(wrap->data.mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	wrap->data.img.addr = mlx_get_data_addr(wrap->data.img.mlx_img,
			&wrap->data.img.bpp, &wrap->data.img.line_len,
			&wrap->data.img.endian);
	pos.x = -1;
	while (++pos.x < wrap->map->dims.width)
	{
		pos.y = -1;
		while (++pos.y < wrap->map->dims.height)
		{
			start.x = wrap->map->content[pos.y][pos.x].pos.x
				* wrap->map->zoom + WINDOW_WIDTH / 2 + wrap->map->offset.x;
			start.y = wrap->map->content[pos.y][pos.x].pos.y
				* wrap->map->zoom + WINDOW_HEIGHT / 2 + wrap->map->offset.y;
			if (pos.y < wrap->map->dims.height - 1)
				draw_vertical_lines(wrap, pos.x, pos.y, start);
			if (pos.x < wrap->map->dims.width - 1)
				draw_horizontal_lines(wrap, pos.x, pos.y, start);
		}
	}
	draw_helper(wrap);
	mlx_clear_window(wrap->data.mlx_ptr, wrap->data.win_ptr);
	mlx_put_image_to_window(wrap->data.mlx_ptr, wrap->data.win_ptr,
		wrap->data.img.mlx_img, 0, 0);
	mlx_destroy_image(wrap->data.mlx_ptr, wrap->data.img.mlx_img);
	if (wrap->menu)
		display_menu(wrap);
}

int	get_pixel_image_color(t_wrapper wrapper, t_2vec pos)
{
	char	*pixel;

	pixel = wrapper.data.img.addr + pos.x * wrapper.data.img.line_len + pos.y
		* (wrapper.data.img.bpp / 8);
	return (*(int *) pixel);
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
		if (start.x >= 0 && start.x <= WINDOW_WIDTH && start.y >= 0 && start.y
			<= WINDOW_HEIGHT)
			img_pix_put(&wrapper.data.img, start.x, start.y, get_color2(color,
					line_length, pos));
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
