/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:00:00 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/25 16:15:20 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	change_zoom(t_wrapper *wrapper)
{
	float	before;

	before = wrapper->map->zoom;
	if (inlist(wrapper->keys, PAGEUP))
		wrapper->map->zoom *= ZOOM_MODIFIER;
	else
		wrapper->map->zoom /= ZOOM_MODIFIER;
	if (wrapper->map->zoom < 0.5f)
		wrapper->map->zoom = before;
	display_map(wrapper);
}

void	translate_camera(t_wrapper *wrapper)
{
	if (inlist(wrapper->keys, UP_ARROW_CODE))
		wrapper->map->offset.y += WINDOW_HEIGHT / wrapper->offset_div;
	if (inlist(wrapper->keys, DOWN_ARROW_CODE))
		wrapper->map->offset.y -= WINDOW_HEIGHT / wrapper->offset_div;
	if (inlist(wrapper->keys, LEFT_ARROW_CODE))
		wrapper->map->offset.x += WINDOW_WIDTH / wrapper->offset_div;
	if (inlist(wrapper->keys, RIGHT_ARROW_CODE))
		wrapper->map->offset.x -= WINDOW_WIDTH / wrapper->offset_div;
	display_map(wrapper);
}

void	change_height(t_wrapper *wrapper)
{
	float	before;

	before = wrapper->map->height_div;
	if (inlist(wrapper->keys, K_CODE))
		wrapper->map->height_div *= HEIGHT_MODIFIER;
	else
		wrapper->map->height_div /= HEIGHT_MODIFIER;
	if (wrapper->map->height_div > 100)
		wrapper->map->height_div = before;
	refill_map(wrapper);
	base_rotate(wrapper);
	display_map(wrapper);
}

void	reset_map(t_wrapper *wrapper)
{
	refill_map(wrapper);
	base_rotate(wrapper);
	display_map(wrapper);
}
