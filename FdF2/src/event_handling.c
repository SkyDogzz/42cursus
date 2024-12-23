/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:32:37 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/23 17:52:44 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	exit_msg_code(const char *message, int code)
{
	ft_dprintf(2, "%s", message);
	exit(code);
}

int	full_quit(t_wrapper *wrapper)
{
	mlx_destroy_window(wrapper->data.mlx_ptr, wrapper->data.win_ptr);
	free_keys(&wrapper->keys);
	return (0);
}

int	change_translate_div(t_wrapper *wrapper)
{
	t_list	*keys;
	int		mult;

	keys = wrapper->keys;
	mult = 1;
	if (inlist(keys, SHIFT_CODE))
		mult = 5;
	else if (inlist(keys, CTRL_CODE))
		mult = 25;
	if (inlist(keys, COMMA_CODE))
		wrapper->offset_div -= mult;
	else
		wrapper->offset_div += mult;
	if (wrapper->offset_div < 2)
		wrapper->offset_div = 2;
	display_map(wrapper);
	return (0);
}

int	change_rotation_div(t_wrapper *wrapper)
{	
	t_list	*keys;
	int		mult;

	keys = wrapper->keys;
	mult = 1;
	if (inlist(keys, SHIFT_CODE))
		mult = 10;
	else if (inlist(keys, CTRL_CODE))
			mult = 100;
	if (inlist(keys, BRACE_O_CODE))
		wrapper->rotate_div -= mult;
	else
		wrapper->rotate_div += mult;
	if (wrapper->rotate_div < 2)
		wrapper->rotate_div = 2;
	display_map(wrapper);
	return (0);
}

int	handle_rotation_translation(t_wrapper *wrapper)
{
	t_list	*keys;

	keys = wrapper->keys;
	if (inlist(keys, X_CODE) || inlist(keys, Y_CODE)
		|| inlist(keys, Z_CODE))
		rotate(wrapper);
	if (inlist(keys, LEFT_ARROW_CODE) || inlist(keys, UP_ARROW_CODE)
		|| inlist(keys, RIGHT_ARROW_CODE) || inlist(keys, DOWN_ARROW_CODE))
		translate_camera(wrapper);
	if (inlist(keys, COMMA_CODE) || inlist(keys, DOT_CODE))
		change_translate_div(wrapper);
	if (inlist(keys, BRACE_O_CODE) || inlist(keys, BRACE_C_CODE))
		change_rotation_div(wrapper);
	return (0);
}

int	handle_misc(t_wrapper *wrapper)
{
	t_list	*keys;

	keys = wrapper->keys;
	if (inlist(keys, H_CODE))
		toggle_helper(wrapper);
	if (inlist(keys, SPACE_CODE))
		toggle_menu(wrapper);
	if (inlist(keys, C_CODE))
		change_all_color(wrapper);
	if (inlist(keys, R_CODE))
		randomize_color(wrapper);
	if (inlist(keys, W_CODE))
		reset_map(wrapper);
	if (inlist(keys, J_CODE) || inlist(keys, K_CODE))
		change_height(wrapper);
	if (inlist(keys, PAGEUP) || inlist(keys, PAGEDOWN))
		change_zoom(wrapper);
	return (0);
}

int	handle_keypress(int keycode, t_wrapper *wrapper)
{
	add_key(&wrapper->keys, keycode);
	handle_misc(wrapper);
	if (keycode == ESC_CODE)
		full_quit(wrapper);
	return (0);
}

int	handle_keyrelease(int keycode, t_wrapper *wrapper)
{
	remove_key(&wrapper->keys, keycode);
	return (0);
}

int	atoi_base(const char *s, const char *base, const char *base2)
{
	int	nbr;
	int	pos;
	int	flag;

	nbr = 0;
	while (*s)
	{
		pos = 0;
		flag = 0;
		while (base[pos] && base2[pos])
		{
			if (base[pos] == *s || base2[pos] == *s)
			{
				nbr *= ft_strlen(base);
				nbr += pos;
				flag = 1;
			}
			pos++;
		}
		if (flag == 0)
			return (nbr);
		s++;
	}
	return (nbr);
}
