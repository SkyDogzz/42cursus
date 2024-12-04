/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:44:02 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/04 15:54:32 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char *argv[])
{
	t_wrapper	wrapper;

	if (argc <= 1)
	{
		ft_dprintf(2, "Usage: %s <input_file>\n", argv[0]);
		exit(0);
	}
	wrapper.menu = MENU;
	wrapper.map = parse_map(argv[1]);
	wrapper.map->filename = argv[1];
	setup_map(&wrapper);
	wrapper.data.mlx_ptr = mlx_init();
	wrapper.data.win_ptr = mlx_new_window(wrapper.data.mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, "FdF Goes Brrr!!!");
	mlx_loop_hook(wrapper.data.mlx_ptr, &handle_no_event, &wrapper);
	mlx_key_hook(wrapper.data.win_ptr, &handle_key, &wrapper);
	mlx_hook(wrapper.data.win_ptr, 17, 0, &full_quit, &wrapper.data);
	base_rotate(&wrapper);
	display_map(&wrapper);
	mlx_loop(wrapper.data.mlx_ptr);
	mlx_destroy_display(wrapper.data.mlx_ptr);
	free(wrapper.data.mlx_ptr);
	free_map_full(wrapper.map);
	return (EXIT_SUCCESS);
}
