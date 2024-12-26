/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:00:00 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/26 10:49:44 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	img_pix_get(const t_img *img, int x, int y)
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
	t_lineinfo	info;
	t_3vec		end;
	int			i1;
	int			i2;

	i1 = y * w->map->dims.width + x;
	i2 = (y + 1) * w->map->dims.width + x;
	info.color.start = w->map->content[i1].color;
	info.color.end = w->map->content[i2].color;
	info.start.x = start2d.x;
	info.start.y = start2d.y;
	info.start.z = w->map->content[i1].pos.z;
	end = w->map->content[i2].pos;
	info.end.x = (int)(end.x * w->map->zoom
			+ (float)WINDOW_WIDTH / 2 + w->map->offset.x);
	info.end.y = (int)(end.y * w->map->zoom
			+ (float)WINDOW_HEIGHT / 2 + w->map->offset.y);
	info.end.z = end.z;
	draw_line_zbuffer(&info, w);
}

void	draw_horizontal_lines(t_wrapper *w, int x, int y, t_2vec start2d)
{
	t_lineinfo	info;
	t_3vec		end;
	int			i1;
	int			i2;

	i1 = y * w->map->dims.width + x;
	i2 = y * w->map->dims.width + (x + 1);
	end = w->map->content[i2].pos;
	info.color.start = w->map->content[i1].color;
	info.color.end = w->map->content[i2].color;
	info.start.x = start2d.x;
	info.start.y = start2d.y;
	info.start.z = w->map->content[i1].pos.z;
	info.end.x = (int)(end.x * w->map->zoom
			+ (float)WINDOW_WIDTH / 2 + w->map->offset.x);
	info.end.y = (int)(end.y * w->map->zoom
			+ (float)WINDOW_HEIGHT / 2 + w->map->offset.y);
	info.end.z = end.z;
	draw_line_zbuffer(&info, w);
}
