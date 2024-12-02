/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:44:02 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/02 02:06:19 by skydogzz         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_map	*map;
	t_mlx	data;

	if (argc <= 1)
	{
		ft_dprintf(2, "Usage: %s <input_file>\n", argv[0]);
		exit(0);
	}
	map = parse_map(argv[1]);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 400, "FdF Goes Brrr!!!");
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_key_hook(data.win_ptr, &handle_key, &data);
	mlx_mouse_hook(data.win_ptr, &handle_mouse, &data);
	mlx_hook(data.win_ptr, 17, 0, &full_quit, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free_map_full(map);
	return (EXIT_SUCCESS);
}
