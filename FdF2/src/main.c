/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:44:02 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/02 17:32:28 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_map_full(t_map *map)
{
	while (map->dims.height--)
	{
		free(map->content[map->dims.height]);
	}
	free(map->content);
	free(map);
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

# define PI 3.1415

int	main(int argc, char *argv[])
{
	t_wrapper wrapper;

	if (argc <= 1)
	{
		ft_dprintf(2, "Usage: %s <input_file>\n", argv[0]);
		exit(0);
	}
	wrapper.map = parse_map(argv[1]);
	wrapper.data.mlx_ptr = mlx_init();
	wrapper.data.win_ptr = mlx_new_window(wrapper.data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF Goes Brrr!!!");
	mlx_loop_hook(wrapper.data.mlx_ptr, &handle_no_event, &wrapper);
	mlx_key_hook(wrapper.data.win_ptr, &handle_key, &wrapper.data);
	mlx_mouse_hook(wrapper.data.win_ptr, &handle_mouse, &wrapper.data);
	mlx_hook(wrapper.data.win_ptr, 17, 0, &full_quit, &wrapper.data);
	rotatex_map(wrapper.map, PI / 4);
	display_map(wrapper.data, *wrapper.map);
	mlx_loop(wrapper.data.mlx_ptr);
	mlx_destroy_display(wrapper.data.mlx_ptr);
	free(wrapper.data.mlx_ptr);
	free_map_full(wrapper.map);
	return (EXIT_SUCCESS);
}
