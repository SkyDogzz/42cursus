/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:00:00 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/26 11:40:36 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	t_wrapper	wrapper;

	if (argc <= 1)
	{
		ft_dprintf(2, "Usage: %s <input_file>\n", argv[0]);
		return (1);
	}
	wrapper.map = parse_map(argv[1]);
	if (!wrapper.map)
		exit_msg_code("Error: parse_map failed\n", 1);
	wrapper.data.mlx_ptr = mlx_init();
	if (!wrapper.data.mlx_ptr)
		exit_msg_code("Error: MLX init failed\n", 1);
	wrapper.data.win_ptr = mlx_new_window(wrapper.data.mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
	if (!wrapper.data.win_ptr)
		exit_msg_code("Error: Window init failed\n", 1);
	setup_map(&wrapper);
	setup(&wrapper);
	display_map(&wrapper);
	mlx_loop(wrapper.data.mlx_ptr);
	return (0);
}
