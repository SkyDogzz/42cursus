/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:00:00 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/26 10:40:26 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	init_line_params(t_line_params *p, t_3vec s, t_3vec e)
{
	p->p0.x = (int)s.x;
	p->p0.y = (int)s.y;
	p->p1.x = (int)e.x;
	p->p1.y = (int)e.y;
	p->d.x = ft_abs(p->p1.x - p->p0.x);
	if (p->p0.x < p->p1.x)
		p->step.x = 1;
	else
		p->step.x = -1;
	p->d.y = -ft_abs(p->p1.y - p->p0.y);
	if (p->p0.y < p->p1.y)
		p->step.y = 1;
	else
		p->step.y = -1;
	p->err.x = p->d.x + p->d.y;
	p->steps = sqrtf((e.x - s.x) * (e.x - s.x) + (e.y - s.y) * (e.y - s.y));
	if (p->steps < 1.0f)
		p->steps = 1.0f;
	p->dz = (e.z - s.z) / p->steps;
	p->current_z = s.z;
	p->t = 0.0f;
}

void	compute_color(t_line_params *p, t_2color color)
{
	p->start.r = (color.start >> 16) & 0xFF;
	p->start.g = (color.start >> 8) & 0xFF;
	p->start.b = color.start & 0xFF;
	p->end.r = (color.end >> 16) & 0xFF;
	p->end.g = (color.end >> 8) & 0xFF;
	p->end.b = color.end & 0xFF;
}

void	draw_pixel(t_line_params *p, t_wrapper *w)
{
	float	fraction;
	int		final_color;
	int		id;

	if (p->p0.x >= 0 && p->p0.x < WINDOW_WIDTH
		&& p->p0.y >= 0 && p->p0.y < WINDOW_HEIGHT)
	{
		fraction = p->t / p->steps;
		final_color = ((p->start.r + (int)((p->end.r - p->start.r)
						* fraction)) << 16)
			| ((p->start.g + (int)((p->end.g - p->start.g) * fraction)) << 8)
			| (p->start.b + (int)((p->end.b - p->start.b) * fraction));
		id = p->p0.y * WINDOW_WIDTH + p->p0.x;
		if (p->current_z < w->z_buffer[id])
		{
			img_pix_put(&w->data.img, p->p0.x, p->p0.y, final_color);
			w->z_buffer[id] = p->current_z;
		}
	}
}

void	draw_line_zbuffer(const t_lineinfo *info, t_wrapper *wrapper)
{
	t_line_params	p;

	init_line_params(&p, info->start, info->end);
	compute_color(&p, info->color);
	while (1)
	{
		draw_pixel(&p, wrapper);
		if (p.p0.x == p.p1.x && p.p0.y == p.p1.y)
			break ;
		p.err.y = p.err.x * 2;
		if (p.err.y >= p.d.y)
		{
			p.err.x += p.d.y;
			p.p0.x += p.step.x;
		}
		if (p.err.y <= p.d.x)
		{
			p.err.x += p.d.x;
			p.p0.y += p.step.y;
		}
		p.t += 1.0f;
		p.current_z += p.dz;
	}
}

void	img_pix_put(const t_img *img, int x, int y, int color)
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
