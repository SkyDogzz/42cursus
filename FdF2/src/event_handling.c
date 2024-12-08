/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:32:37 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/08 17:12:37 by skydogzz         ###   ########.fr       */
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

int	handle_rotation_translation(t_wrapper *wrapper)
{
	t_list	*keys;

	keys = wrapper->keys;
	if (inlist(keys, X_CODE) || inlist(keys, Y_CODE) ||
		inlist(keys, Z_CODE))
			rotate(wrapper);
	if (inlist(keys, LEFT_ARROW_CODE) || inlist(keys, UP_ARROW_CODE) ||
		inlist(keys, RIGHT_ARROW_CODE) || inlist(keys, DOWN_ARROW_CODE))
			translate_camera(wrapper);
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
	return (0);
}

int	handle_keypress(int keycode, t_wrapper *wrapper)
{
	ft_printf("keycode = %d\n", keycode);
	add_key(&wrapper->keys, keycode);
	if (keycode == ESC_CODE)
		full_quit(wrapper);
	handle_rotation_translation(wrapper);
	handle_misc(wrapper);
	return (0);
}

int	handle_keyrelease(int keycode, t_wrapper *wrapper)
{
	remove_key(&wrapper->keys, keycode);
	return (0);
}
// int	handle_key(int keycode, t_wrapper *wrapper)
// {
// 	else if (keycode == PAGEUP || keycode == PAGEDOWN)
// 		change_zoom(wrapper, keycode);
// 	else if (keycode == C_CODE)
// 		change_all_color(wrapper);
// 	else if (keycode == R_CODE)
// 		randomize_color(wrapper);
// 	else if (keycode == W_CODE)
// 		reset_map(wrapper);
// 	else if (keycode == J_CODE || keycode == K_CODE)
// 		change_height(wrapper, keycode);
// 	return (0);
// }
//

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
