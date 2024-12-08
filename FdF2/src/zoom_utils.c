/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:11:36 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/08 17:19:27 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	change_zoom(t_wrapper *wrapper)
{
	if (inlist(wrapper->keys, PAGEUP))
		wrapper->map->zoom *= ZOOM_MODIFIER;
	else
		wrapper->map->zoom /= ZOOM_MODIFIER;
	display_map(wrapper);
}

void	translate_camera(t_wrapper *wrapper)
{
	t_list	*keys;

	keys = wrapper->keys;
	if (inlist(keys, UP_ARROW_CODE))
		wrapper->map->offset.y += WINDOW_HEIGHT / OFFSET_DIV;
	if (inlist(keys, DOWN_ARROW_CODE))
		wrapper->map->offset.y -= WINDOW_HEIGHT / OFFSET_DIV;
	if (inlist(keys, LEFT_ARROW_CODE))
		wrapper->map->offset.x += WINDOW_WIDTH / OFFSET_DIV;
	if (inlist(keys, RIGHT_ARROW_CODE))
		wrapper->map->offset.x -= WINDOW_WIDTH / OFFSET_DIV;
	display_map(wrapper);
}

void	change_height(t_wrapper *wrapper)
{
	if (inlist(wrapper->keys, K_CODE))
		wrapper->map->height_div *= HEIGHT_MODIFIER;
	else
		wrapper->map->height_div /= HEIGHT_MODIFIER;
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
