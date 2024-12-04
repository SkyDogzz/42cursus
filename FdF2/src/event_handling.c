/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:32:37 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/04 15:42:24 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	exit_msg_code(const char *message, int code)
{
	ft_dprintf(2, "%s", message);
	exit(code);
}

int	full_quit(t_mlx *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
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
	else if (keycode == H_CODE)
		toggle_helper(wrapper);
	return (0);
}

int	handle_mouse(void)
{
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
