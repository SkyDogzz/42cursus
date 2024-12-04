/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:35:19 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/04 12:48:24 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	translate_camera(t_wrapper *wrapper, int keycode)
{
	if (keycode == UP_ARROW_CODE)
		wrapper->map->offset.y += WINDOW_HEIGHT / OFFSET_DIV;
	else if (keycode == DOWN_ARROW_CODE)
		wrapper->map->offset.y -= WINDOW_HEIGHT / OFFSET_DIV;
	else if (keycode == LEFT_ARROW_CODE)
		wrapper->map->offset.x += WINDOW_WIDTH / OFFSET_DIV;
	else if (keycode == RIGHT_ARROW_CODE)
		wrapper->map->offset.x -= WINDOW_WIDTH / OFFSET_DIV;
	mlx_clear_window(wrapper->data.mlx_ptr, wrapper->data.win_ptr);
	display_map(wrapper);
}
