/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:53:55 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/29 19:02:33 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_line(t_mlx mlxs, t_2vector start, t_2vector end, int color)
{
	t_2vector	d;
	t_2vector	p;
	int			m;

	d.x = end.x - start.x;
	d.y = end.y - start.y;
	m = d.y / d.x;
	p.x = start.x;
	while (p.x <= end.x)
	{
		p.y = m * (p.x - start.x) + start.y;
		mlx_pixel_put(mlxs.mlx_ptr, mlxs.win_ptr, p.x, p.y, color);
		p.x++;
	}
}
