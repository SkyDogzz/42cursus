/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:53:55 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/29 16:11:28 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_line(t_mlx mlxs, t_2vector start, t_2vector end, int color)
{
	int	dx;
	int dy;
	int	m;
	int	x;
	int	y;

	dx = end.x - start.x;
	dy = end.y - start.y;
	m = dy / dx;
	x = start.x;
	while (x <= end.x)
	{
		y = m * (x - start.x) + start.y;
		mlx_pixel_put(mlxs.mlx_ptr, mlxs.win_ptr, x, y, color);
		x++;
	}
}
