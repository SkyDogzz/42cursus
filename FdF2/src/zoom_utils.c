/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:11:36 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/04 15:43:23 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	change_zoom(t_wrapper *wrapper, int keycode)
{
	if (keycode == PAGEUP)
		wrapper->map->zoom *= ZOOM_MODIFIER;
	else
		wrapper->map->zoom /= ZOOM_MODIFIER;
	mlx_clear_window(wrapper->data.mlx_ptr, wrapper->data.win_ptr);
	display_map(wrapper);
}

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

void	change_height(t_wrapper *wrapper, int keycode)
{
	if (keycode == K_CODE)
		wrapper->map->height_div *= HEIGHT_MODIFIER;
	else
		wrapper->map->height_div /= HEIGHT_MODIFIER;
	refill_map(wrapper);
	base_rotate(wrapper);
	mlx_clear_window(wrapper->data.mlx_ptr, wrapper->data.win_ptr);
	display_map(wrapper);
}

void	reset_map(t_wrapper *wrapper)
{
	refill_map(wrapper);
	base_rotate(wrapper);
	mlx_clear_window(wrapper->data.mlx_ptr, wrapper->data.win_ptr);
	display_map(wrapper);
}
