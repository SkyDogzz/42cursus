/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:00:00 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/26 11:32:43 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	setup_map(t_wrapper *wrapper)
{
	wrapper->menu = MENU;
	wrapper->map->offset.x = 0;
	wrapper->map->offset.y = 0;
	wrapper->map->helper = HELPER;
	wrapper->offset_div = OFFSET_DIV;
	wrapper->rotate_div = ROTATE_DIV;
	wrapper->total_frame = 0;
}

void	setup(t_wrapper *wrapper)
{
	mlx_loop_hook(wrapper->data.mlx_ptr, &handle_no_event, wrapper);
	wrapper->keys = NULL;
	mlx_hook(wrapper->data.win_ptr, 17, 0, &full_quit, wrapper);
	mlx_hook(wrapper->data.win_ptr, KeyPress,
		KeyPressMask, &handle_keypress, wrapper);
	mlx_hook(wrapper->data.win_ptr, KeyRelease,
		KeyReleaseMask, &handle_keyrelease, wrapper);
	mlx_do_key_autorepeatoff(wrapper->data.mlx_ptr);
	base_rotate(wrapper);
	wrapper->z_buffer = malloc(sizeof(float)
			* WINDOW_WIDTH * WINDOW_HEIGHT);
	if (!wrapper->z_buffer)
		exit_msg_code("Cannot allocate z-buffer\n", 1);
}
