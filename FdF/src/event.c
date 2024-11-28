/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:55:54 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/28 18:06:07 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	full_quit(t_mlx *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int	handle_key(int keysym, t_mlx *data)
{
	ft_printf("%d key pressed\n", keysym);
	if (keysym == XK_Escape)
		full_quit(data);
	return (0);
}

int	handle_mouse(int button, int x, int y, void *params)
{
	ft_printf("%d button pressed at %d %d\n", button, x, y);
	return (0);
}

int	handle_no_event(void)
{
	return (0);
}
