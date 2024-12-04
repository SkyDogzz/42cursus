/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:25:52 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/04 15:26:56 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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
			pos = map->content[y][x].pos;
			yp = pos.y * cos(angle) - pos.z * sin(angle);
			zp = pos.y * sin(angle) + pos.z * cos(angle);
			map->content[y][x].pos.y = yp;
			map->content[y][x].pos.z = zp;
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
			pos = map->content[y][x].pos;
			xp = pos.x * cos(angle) + pos.z * sin(angle);
			zp = -pos.x * sin(angle) + pos.z * cos(angle);
			map->content[y][x].pos.x = xp;
			map->content[y][x].pos.z = zp;
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
			pos = map->content[y][x].pos;
			xp = pos.x * cos(angle) - pos.y * sin(angle);
			map->content[y][x].pos.x = xp;
			yp = pos.x * sin(angle) + pos.y * cos(angle);
			map->content[y][x].pos.y = yp;
			y++;
		}
		x++;
	}
}

void	rotate(t_wrapper *wrapper, int keycode)
{
	if (keycode == X_CODE)
		rotatex_map(wrapper->map, M_PI / ROTATE_DIV);
	if (keycode == Y_CODE)
		rotatey_map(wrapper->map, M_PI / ROTATE_DIV);
	if (keycode == Z_CODE)
		rotatez_map(wrapper->map, M_PI / ROTATE_DIV);
	mlx_clear_window(wrapper->data.mlx_ptr, wrapper->data.win_ptr);
	display_map(wrapper);
}

void	base_rotate(t_wrapper *wrapper)
{
	rotatex_map(wrapper->map, M_PI / 32 * 10);
	rotatey_map(wrapper->map, M_PI / 32 * 7);
	rotatez_map(wrapper->map, -M_PI / 32 * 4);
}
