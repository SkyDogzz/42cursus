/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 01:36:47 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/03 19:42:13 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	full_quit(t_mlx *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

void	change_zoom(t_wrapper *wrapper, int keycode)
{
	if (keycode == PAGEUP)
		wrapper->map->zoom += 0.5;
	else
		wrapper->map->zoom -= 0.5;
	mlx_clear_window(wrapper->data.mlx_ptr, wrapper->data.win_ptr);
	display_map(wrapper->data, *wrapper->map);
}

int	handle_key(int keycode, t_wrapper *wrapper)
{
	if (keycode == ESC_CODE)
		full_quit(&wrapper->data);
	else if (keycode == X_CODE || keycode == Y_CODE || keycode == Z_CODE)
		rotate(wrapper, keycode);
	else if (keycode == PAGEUP || keycode == PAGEDOWN)
		change_zoom(wrapper, keycode);
	else if (keycode == C_CODE)
		change_all_color(wrapper);
	else if (keycode == R_CODE)
		randomize_color(wrapper);
	return (0);
}

int	handle_no_event(t_wrapper *wrapper)
{
	t_mlx	data;
	t_map	*map;

	data = wrapper->data;
	map = wrapper->map;
	return (0);
}

int	handle_mouse(void)
{
	return (0);
}
