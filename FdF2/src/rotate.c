/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:22:42 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/03 19:38:55 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotatex_map(t_map *map, float angle)
{
	float	yp;
	float	zp;
	t_3vec	pos;

	for (int x = 0; x < map->dims.width; x++)
		for (int y = 0; y < map->dims.height; y++)
		{
			pos = map->content[y][x].pos;
			yp = pos.y * cos(angle) - pos.z * sin(angle);
			map->content[y][x].pos.y = yp;
			zp = pos.y * sin(angle) + pos.z * cos(angle);
			map->content[y][x].pos.z = zp;
		}
}

void	rotatey_map(t_map *map, float angle)
{
	float	xp;
	float	zp;
	t_3vec	pos;

	for (int x = 0; x < map->dims.width; x++)
		for (int y = 0; y < map->dims.height; y++)
		{
			pos = map->content[y][x].pos;
			xp = pos.x * cos(angle) + pos.z * sin(angle);
			map->content[y][x].pos.x = xp;
			zp = -pos.x * sin(angle) + pos.z * cos(angle);
			map->content[y][x].pos.z = zp;
		}
}

void	rotatez_map(t_map *map, float angle)
{
	float	xp;
	float	yp;
	t_3vec	pos;

	for (int x = 0; x < map->dims.width; x++)
		for (int y = 0; y < map->dims.height; y++)
		{
			pos = map->content[y][x].pos;
			xp = pos.x * cos(angle) - pos.y * sin(angle);
			map->content[y][x].pos.x = xp;
			yp = pos.x * sin(angle) + pos.y * cos(angle);
			map->content[y][x].pos.y = yp;
		}
}

void	rotate(t_wrapper *wrapper, int keycode)
{
	if (keycode == X_CODE)
		rotatex_map(wrapper->map, PI / 16);
	if (keycode == Y_CODE)
		rotatey_map(wrapper->map, PI / 16);
	if (keycode == Z_CODE)
		rotatez_map(wrapper->map, PI / 16);
	mlx_clear_window(wrapper->data.mlx_ptr, wrapper->data.win_ptr);
	display_map(wrapper->data, *wrapper->map);
}
