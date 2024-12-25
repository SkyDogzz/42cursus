/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:27:23 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/25 16:02:21 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	display_map_loop(t_wrapper *wrap, t_2vec *pos)
{
	t_2vec	start;

	while (++pos->x < wrap->map->dims.width)
	{
		pos->y = -1;
		while (++pos->y < wrap->map->dims.height)
		{
			start.x = wrap->map->content[pos->y * wrap->map->dims.width
				+ pos->x].pos.x
				* wrap->map->zoom + WINDOW_WIDTH / 2 + wrap->map->offset.x;
			start.y = wrap->map->content[pos->y * wrap->map->dims.width
				+ pos->x].pos.y
				* wrap->map->zoom + WINDOW_HEIGHT / 2 + wrap->map->offset.y;
			if (pos->y < wrap->map->dims.height - 1)
				draw_vertical_lines(wrap, pos->x, pos->y, start);
			if (pos->x < wrap->map->dims.width - 1)
				draw_horizontal_lines(wrap, pos->x, pos->y, start);
		}
	}
}

void	clear_zbuffer(float *zbuffer, int width, int height)
{
	int	i;

	i = 0;
	while (i < width * height)
	{
		zbuffer[i] = FLT_MAX;
		i++;
	}
}

void	display_map(t_wrapper *wrap)
{
	t_2vec	pos;

	wrap->data.img.mlx_img = mlx_new_image(wrap->data.mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	wrap->data.img.addr = mlx_get_data_addr(wrap->data.img.mlx_img,
			&wrap->data.img.bpp, &wrap->data.img.line_len,
			&wrap->data.img.endian);
	clear_zbuffer(wrap->z_buffer, WINDOW_WIDTH, WINDOW_HEIGHT);
	pos.x = -1;
	display_map_loop(wrap, &pos);
	draw_helper(wrap);
	mlx_put_image_to_window(wrap->data.mlx_ptr, wrap->data.win_ptr,
		wrap->data.img.mlx_img, 0, 0);
	if (wrap->menu)
		display_menu(wrap);
	mlx_destroy_image(wrap->data.mlx_ptr, wrap->data.img.mlx_img);
}

int	img_pix_get(t_img *img, int x, int y)
{
	char	*pixel;
	int		i;
	int		color;

	color = 0;
	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			color |= (*pixel++ & 0xFF) << i;
		else
			color |= (*pixel++ & 0xFF) << (img->bpp - 8 - i);
		i -= 8;
	}
	return (color);
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
			if (img_pix_get(&wrapper.data.img, start.x, start.y) == 0)
				img_pix_put(&wrapper.data.img, start.x, start.y,
					get_color2(color, line_length, pos));
		if (start.x == end.x && start.y == end.y)
			break ;
		update_position(&start, &s, &e, &d);
		pos++;
	}
}

void	init_line_params(t_line_params *params, float sx, float sy, float sz, float ex, float ey, float ez)
{
	params->x0 = (int)sx;
	params->y0 = (int)sy;
	params->x1 = (int)ex;
	params->y1 = (int)ey;
	params->dx = abs(params->x1 - params->x0);
	params->sxstep = (params->x0 < params->x1) ? 1 : -1;
	params->dy = -abs(params->y1 - params->y0);
	params->systep = (params->y0 < params->y1) ? 1 : -1;
	params->err = params->dx + params->dy;
	params->steps = sqrtf(powf(ex - sx, 2) + powf(ey - sy, 2));
	params->steps = (params->steps < 1.0f) ? 1.0f : params->steps;
	params->dz = (ez - sz) / params->steps;
	params->current_z = sz;
	params->t = 0.0f;
}

void    compute_color(t_line_params *params, t_2color color)
{
	params->sr = (color.start >> 16) & 0xFF;
	params->sg = (color.start >> 8) & 0xFF;
	params->sb = color.start & 0xFF;
	params->er = (color.end >> 16) & 0xFF;
	params->eg = (color.end >> 8) & 0xFF;
	params->eb = color.end & 0xFF;
}

void    draw_pixel(t_line_params *params, t_wrapper *wrapper)
{
	float fraction;
	int   final_color;

	if (params->x0 >= 0 && params->x0 < WINDOW_WIDTH
		&& params->y0 >= 0 && params->y0 < WINDOW_HEIGHT)
	{
		fraction = params->t / params->steps;
		final_color = ((params->sr + (int)((params->er - params->sr) * fraction)) << 16)
			| ((params->sg + (int)((params->eg - params->sg) * fraction)) << 8)
			| (params->sb + (int)((params->eb - params->sb) * fraction));
		params->current_z = params->current_z + params->dz;
		if (params->current_z < wrapper->z_buffer[(int) (params->y0 * WINDOW_WIDTH + params->x0)])
		{
			img_pix_put(&wrapper->data.img, params->x0, params->y0, final_color);
			wrapper->z_buffer[(int) (params->y0 * WINDOW_WIDTH + params->x0)] = params->current_z;
		}
	}
}

void    draw_line_zbuffer(
	float sx, float sy, float sz,
	float ex, float ey, float ez,
	t_2color color, t_wrapper *wrapper)
{
	t_line_params params;

	init_line_params(&params, sx, sy, sz, ex, ey, ez);
	compute_color(&params, color);
	while (1)
	{
		draw_pixel(&params, wrapper);
		if (params.x0 == params.x1 && params.y0 == params.y1)
			break ;
		params.e2 = 2 * params.err;
		if (params.e2 >= params.dy)
		{
			params.err += params.dy;
			params.x0 += params.sxstep;
		}
		if (params.e2 <= params.dx)
		{
			params.err += params.dx;
			params.y0 += params.systep;
		}
		params.t += 1.0f;
	}
}

void	draw_vertical_lines(t_wrapper *wrapper, int x, int y, t_2vec start2d)
{
	t_3vec		start3d;
	t_3vec		end3d;
	t_2color	color;
	t_2vec		end2d;

	start3d = wrapper->map->content[y * wrapper->map->dims.width + x].pos;
	end3d = wrapper->map->content[(y + 1) * wrapper->map->dims.width + x].pos;
	color.start = wrapper->map->content[y * wrapper->map->dims.width + x].color;
	color.end   = wrapper->map->content[(y + 1) * wrapper->map->dims.width + x].color;
	end2d.x = wrapper->map->content[(y + 1) * wrapper->map->dims.width + x].pos.x
		* wrapper->map->zoom + WINDOW_WIDTH / 2 + wrapper->map->offset.x;
	end2d.y = wrapper->map->content[(y + 1) * wrapper->map->dims.width + x].pos.y
		* wrapper->map->zoom + WINDOW_HEIGHT / 2 + wrapper->map->offset.y;
	draw_line_zbuffer(
		start2d.x, start2d.y, start3d.z,
		end2d.x,   end2d.y,   end3d.z,
		color,
		wrapper
	);
}

void	draw_horizontal_lines(t_wrapper *wrapper, int x, int y, t_2vec start2d)
{
	t_2vec		end2d;
	t_3vec		start3d;
	t_3vec		end3d;
	t_2color	color;

	start3d = wrapper->map->content[y * wrapper->map->dims.width + x].pos;
	end3d   = wrapper->map->content[y * wrapper->map->dims.width + (x + 1)].pos;
	end2d.x = end3d.x * wrapper->map->zoom 
		+ WINDOW_WIDTH / 2 
		+ wrapper->map->offset.x;
	end2d.y = end3d.y * wrapper->map->zoom 
		+ WINDOW_HEIGHT / 2 
		+ wrapper->map->offset.y;
	color.start = wrapper->map->content[y * wrapper->map->dims.width + x].color;
	color.end   = wrapper->map->content[y * wrapper->map->dims.width + (x + 1)].color;
	draw_line_zbuffer((float)start2d.x, (float)start2d.y, start3d.z,
		(float)end2d.x, (float)end2d.y, end3d.z, color, wrapper);
}
