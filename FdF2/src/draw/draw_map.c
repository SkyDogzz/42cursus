/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:00:00 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/25 16:16:55 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	clear_zbuffer(float *zbuffer, int width, int height)
{
	int	i;
	int	total;

	i = 0;
	total = width * height;
	while (i < total)
	{
		zbuffer[i] = FLT_MAX;
		i++;
	}
}

void	display_map_loop(t_wrapper *wrap, t_2vec *pos)
{
	t_2vec	start2d;

	while (++pos->x < wrap->map->dims.width)
	{
		pos->y = -1;
		while (++pos->y < wrap->map->dims.height)
		{
			start2d.x = (int)(wrap->map->content[pos->y
				* wrap->map->dims.width + pos->x].pos.x
				* wrap->map->zoom
				+ WINDOW_WIDTH / 2 + wrap->map->offset.x);
			start2d.y = (int)(wrap->map->content[pos->y
				* wrap->map->dims.width + pos->x].pos.y
				* wrap->map->zoom
				+ WINDOW_HEIGHT / 2 + wrap->map->offset.y);
			if (pos->y < wrap->map->dims.height - 1)
				draw_vertical_lines(wrap, pos->x, pos->y, start2d);
			if (pos->x < wrap->map->dims.width - 1)
				draw_horizontal_lines(wrap, pos->x, pos->y, start2d);
		}
	}
}

void	display_map(t_wrapper *wrapper)
{
	t_2vec	pos;

	wrapper->data.img.mlx_img = mlx_new_image(
			wrapper->data.mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	wrapper->data.img.addr = mlx_get_data_addr(
			wrapper->data.img.mlx_img,
			&wrapper->data.img.bpp,
			&wrapper->data.img.line_len,
			&wrapper->data.img.endian);
	clear_zbuffer(wrapper->z_buffer, WINDOW_WIDTH, WINDOW_HEIGHT);
	pos.x = -1;
	display_map_loop(wrapper, &pos);
	draw_helper(wrapper);
	mlx_put_image_to_window(wrapper->data.mlx_ptr,
		wrapper->data.win_ptr,
		wrapper->data.img.mlx_img, 0, 0);
	if (wrapper->menu)
		display_menu(wrapper);
	mlx_destroy_image(wrapper->data.mlx_ptr, wrapper->data.img.mlx_img);
}
