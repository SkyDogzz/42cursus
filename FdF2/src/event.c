/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 01:36:47 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/03 13:15:33 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	full_quit(t_mlx *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

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
			zp = - pos.x * sin(angle) + pos.z * cos(angle);
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
		rotatex_map(wrapper->map, PI / 8);
	if (keycode == Y_CODE)
		rotatey_map(wrapper->map, PI / 8);
	if (keycode == Z_CODE)
		rotatez_map(wrapper->map, PI / 8);

}

int	handle_key(int keycode, t_wrapper *wrapper)
{
	if (keycode == ESC_CODE)
	{		
		full_quit(&wrapper->data);
		return (0);
	}
	if (keycode == X_CODE || keycode == Y_CODE || keycode == Z_CODE)
	{
		rotate(wrapper, keycode);
		mlx_clear_window(wrapper->data.mlx_ptr, wrapper->data.win_ptr);
		display_map(wrapper->data, *wrapper->map);
		return (0);
	}
	return (0);
}

int	handle_no_event(t_wrapper *wrapper)
{
	t_mlx	data;
	t_map	*map;

	data = wrapper->data;
	map = wrapper->map;
	return 0;
}

int	handle_mouse(void)
{
	return (0);
}
