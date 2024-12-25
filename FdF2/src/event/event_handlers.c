/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:00:00 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/25 17:13:09 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	handle_no_event(t_wrapper *wrapper)
{
	handle_rotation(wrapper);
	handle_translation(wrapper);
	return (0);
}

int	handle_rotation(t_wrapper *wrapper)
{
	if (inlist(wrapper->keys, X_CODE)
		|| inlist(wrapper->keys, Y_CODE)
		|| inlist(wrapper->keys, Z_CODE))
		rotate(wrapper);
	if (inlist(wrapper->keys, BRACE_O_CODE)
		|| inlist(wrapper->keys, BRACE_C_CODE))
	{
		if (inlist(wrapper->keys, BRACE_O_CODE))
			wrapper->rotate_div -= 1;
		else
			wrapper->rotate_div += 1;
		if (wrapper->rotate_div < 2)
			wrapper->rotate_div = 2;
		display_map(wrapper);
	}
	return (0);
}

int	handle_translation(t_wrapper *wrapper)
{
	if (inlist(wrapper->keys, LEFT_ARROW_CODE)
		|| inlist(wrapper->keys, UP_ARROW_CODE)
		|| inlist(wrapper->keys, RIGHT_ARROW_CODE)
		|| inlist(wrapper->keys, DOWN_ARROW_CODE))
		translate_camera(wrapper);
	if (inlist(wrapper->keys, COMMA_CODE)
		|| inlist(wrapper->keys, DOT_CODE))
	{
		if (inlist(wrapper->keys, COMMA_CODE))
			wrapper->offset_div -= 1;
		else
			wrapper->offset_div += 1;
		if (wrapper->offset_div < 2)
			wrapper->offset_div = 2;
		display_map(wrapper);
	}
	return (0);
}

int	handle_misc(t_wrapper *wrapper)
{
	if (inlist(wrapper->keys, H_CODE))
		toggle_helper(wrapper);
	if (inlist(wrapper->keys, SPACE_CODE))
		toggle_menu(wrapper);
	if (inlist(wrapper->keys, C_CODE))
		change_all_color(wrapper);
	if (inlist(wrapper->keys, R_CODE))
		randomize_color(wrapper);
	if (inlist(wrapper->keys, W_CODE))
		reset_map(wrapper);
	if (inlist(wrapper->keys, J_CODE)
		|| inlist(wrapper->keys, K_CODE))
		change_height(wrapper);
	if (inlist(wrapper->keys, PAGEUP)
		|| inlist(wrapper->keys, PAGEDOWN))
		change_zoom(wrapper);
	return (0);
}
