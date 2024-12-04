/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 01:36:47 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/04 12:51:04 by tstephan         ###   ########.fr       */
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
		wrapper->map->zoom *= ZOOM_MODIFIER;
	else
		wrapper->map->zoom /= ZOOM_MODIFIER;
	mlx_clear_window(wrapper->data.mlx_ptr, wrapper->data.win_ptr);
	display_map(wrapper);
}

void	toggle_menu(t_wrapper *wrapper)
{
	if (wrapper->menu == TRUE)
		wrapper->menu = FALSE;
	else
		wrapper->menu = TRUE;
	mlx_clear_window(wrapper->data.mlx_ptr, wrapper->data.win_ptr);
	display_map(wrapper);
}

void	base_rotate(t_wrapper *wrapper)
{
	rotatex_map(wrapper->map, M_PI / 32 * 10);
	rotatey_map(wrapper->map, M_PI / 32 * 7);
	rotatez_map(wrapper->map, -M_PI / 32 * 4);
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
	else if (keycode == SPACE_CODE)
		toggle_menu(wrapper);
	else if (keycode == W_CODE)
		reset_map(wrapper);
	else if (keycode == J_CODE || keycode == K_CODE)
		change_height(wrapper, keycode);
	else if (keycode >= LEFT_ARROW_CODE && keycode <= DOWN_ARROW_CODE)
		translate_camera(wrapper, keycode);
	// ft_printf("keycode %d\n", keycode);
	return (0);
}

int	handle_no_event(t_wrapper *wrapper)
{
	t_mlx	data;
	t_map	*map;

	data = wrapper->data;
	map = wrapper->map;
	return (0);
	(void) data;
	(void) map;
}

int	handle_mouse(void)
{
	return (0);
}
