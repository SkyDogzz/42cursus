/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:00:00 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/25 16:17:21 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	init_line_params(t_line_params *p,
	float sx, float sy, float sz,
	float ex, float ey, float ez)
{
	p->x0 = (int)sx;
	p->y0 = (int)sy;
	p->x1 = (int)ex;
	p->y1 = (int)ey;
	p->dx = ft_abs(p->x1 - p->x0);
	p->sxstep = (p->x0 < p->x1) ? 1 : -1;
	p->dy = -ft_abs(p->y1 - p->y0);
	p->systep = (p->y0 < p->y1) ? 1 : -1;
	p->err = p->dx + p->dy;
	p->steps = sqrtf((ex - sx) * (ex - sx)
			+ (ey - sy) * (ey - sy));
	if (p->steps < 1.0f)
		p->steps = 1.0f;
	p->dz = (ez - sz) / p->steps;
	p->current_z = sz;
	p->t = 0.0f;
}

void	compute_color(t_line_params *p, t_2color color)
{
	p->sr = (color.start >> 16) & 0xFF;
	p->sg = (color.start >> 8) & 0xFF;
	p->sb = color.start & 0xFF;
	p->er = (color.end >> 16) & 0xFF;
	p->eg = (color.end >> 8) & 0xFF;
	p->eb = color.end & 0xFF;
}

void	draw_pixel(t_line_params *p, t_wrapper *w)
{
	float	fraction;
	int		final_color;
	int		idx;

	if (p->x0 >= 0 && p->x0 < WINDOW_WIDTH
		&& p->y0 >= 0 && p->y0 < WINDOW_HEIGHT)
	{
		fraction = p->t / p->steps;
		final_color = ((p->sr + (int)((p->er - p->sr)
				* fraction)) << 16)
			| ((p->sg + (int)((p->eg - p->sg)
				* fraction)) << 8)
			| (p->sb + (int)((p->eb - p->sb)
				* fraction));
		idx = p->y0 * WINDOW_WIDTH + p->x0;
		if (p->current_z < w->z_buffer[idx])
		{
			img_pix_put(&w->data.img, p->x0, p->y0,
				final_color);
			w->z_buffer[idx] = p->current_z;
		}
	}
}

void	draw_line_zbuffer(
	float sx, float sy, float sz,
	float ex, float ey, float ez,
	t_2color color, t_wrapper *w)
{
	t_line_params	p;

	init_line_params(&p, sx, sy, sz, ex, ey, ez);
	compute_color(&p, color);
	while (1)
	{
		draw_pixel(&p, w);
		if (p.x0 == p.x1 && p.y0 == p.y1)
			break ;
		p.e2 = p.err * 2;
		if (p.e2 >= p.dy)
		{
			p.err += p.dy;
			p.x0 += p.sxstep;
		}
		if (p.e2 <= p.dx)
		{
			p.err += p.dx;
			p.y0 += p.systep;
		}
		p.t += 1.0f;
		p.current_z += p.dz;
	}
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}
