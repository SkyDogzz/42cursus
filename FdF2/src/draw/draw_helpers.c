/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:00:00 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/25 16:17:42 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

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
			color |= (*pixel++ & 0xFF)
				<< (img->bpp - 8 - i);
		i -= 8;
	}
	return (color);
}

void	draw_vertical_lines(t_wrapper *w, int x, int y, t_2vec start2d)
{
	t_3vec	start3d;
	t_3vec	end3d;
	t_2vec	end2d;
	t_2color color;
	int		i1;
	int		i2;

	i1 = y * w->map->dims.width + x;
	i2 = (y + 1) * w->map->dims.width + x;
	start3d = w->map->content[i1].pos;
	end3d = w->map->content[i2].pos;
	color.start = w->map->content[i1].color;
	color.end = w->map->content[i2].color;
	end2d.x = (int)(end3d.x * w->map->zoom
			+ WINDOW_WIDTH / 2 + w->map->offset.x);
	end2d.y = (int)(end3d.y * w->map->zoom
			+ WINDOW_HEIGHT / 2 + w->map->offset.y);
	draw_line_zbuffer(
		(float)start2d.x, (float)start2d.y, start3d.z,
		(float)end2d.x,   (float)end2d.y,   end3d.z,
		color, w
	);
}

void	draw_horizontal_lines(t_wrapper *w, int x, int y, t_2vec start2d)
{
	t_3vec	start3d;
	t_3vec	end3d;
	t_2vec	end2d;
	t_2color color;
	int		i1;
	int		i2;

	i1 = y * w->map->dims.width + x;
	i2 = y * w->map->dims.width + (x + 1);
	start3d = w->map->content[i1].pos;
	end3d = w->map->content[i2].pos;
	color.start = w->map->content[i1].color;
	color.end = w->map->content[i2].color;
	end2d.x = (int)(end3d.x * w->map->zoom
			+ WINDOW_WIDTH / 2 + w->map->offset.x);
	end2d.y = (int)(end3d.y * w->map->zoom
			+ WINDOW_HEIGHT / 2 + w->map->offset.y);
	draw_line_zbuffer(
		(float)start2d.x, (float)start2d.y, start3d.z,
		(float)end2d.x, (float)end2d.y, end3d.z,
		color, w
	);
}
