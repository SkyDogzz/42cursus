/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:00:00 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/25 16:16:33 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	rotatex_map(t_map *map, float angle)
{
	int		x;
	int		y;
	float	yp;
	float	zp;
	t_3vec	pos;

	x = 0;
	while (x < map->dims.width)
	{
		y = 0;
		while (y < map->dims.height)
		{
			pos = map->content[y * map->dims.width + x].pos;
			yp = pos.y * cosf(angle) - pos.z * sinf(angle);
			zp = pos.y * sinf(angle) + pos.z * cosf(angle);
			map->content[y * map->dims.width + x].pos.y = yp;
			map->content[y * map->dims.width + x].pos.z = zp;
			y++;
		}
		x++;
	}
}

void	rotatey_map(t_map *map, float angle)
{
	int		x;
	int		y;
	float	xp;
	float	zp;
	t_3vec	pos;

	x = 0;
	while (x < map->dims.width)
	{
		y = 0;
		while (y < map->dims.height)
		{
			pos = map->content[y * map->dims.width + x].pos;
			xp = pos.x * cosf(angle) + pos.z * sinf(angle);
			zp = -pos.x * sinf(angle) + pos.z * cosf(angle);
			map->content[y * map->dims.width + x].pos.x = xp;
			map->content[y * map->dims.width + x].pos.z = zp;
			y++;
		}
		x++;
	}
}

void	rotatez_map(t_map *map, float angle)
{
	int		x;
	int		y;
	float	xp;
	float	yp;
	t_3vec	pos;

	x = 0;
	while (x < map->dims.width)
	{
		y = 0;
		while (y < map->dims.height)
		{
			pos = map->content[y * map->dims.width + x].pos;
			xp = pos.x * cosf(angle) - pos.y * sinf(angle);
			yp = pos.x * sinf(angle) + pos.y * cosf(angle);
			map->content[y * map->dims.width + x].pos.x = xp;
			map->content[y * map->dims.width + x].pos.y = yp;
			y++;
		}
		x++;
	}
}
