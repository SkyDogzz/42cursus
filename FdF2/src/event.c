/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 01:36:47 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/02 02:07:32 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	full_quit(t_mlx *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int	handle_key(int keycode, t_mlx *data)
{
	if (keycode == ESC_CODE)
		full_quit(data);
	return (0);
}

int	handle_no_event(void)
{
	return (0);
}

int	handle_mouse(void)
{
	return (0);
}
