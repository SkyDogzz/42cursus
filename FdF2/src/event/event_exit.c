/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:00:00 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/26 11:46:12 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	exit_msg_code(const char *message, int code)
{
	ft_dprintf(2, "%s", message);
	exit(code);
}

int	full_quit(t_wrapper *wrapper)
{
	mlx_destroy_window(wrapper->data.mlx_ptr, wrapper->data.win_ptr);
	free_keys(&wrapper->keys);
	if (wrapper->z_buffer)
		free(wrapper->z_buffer);
	free_map_full(wrapper->map);
	mlx_destroy_display(wrapper->data.mlx_ptr);
	free(wrapper->data.mlx_ptr);
	exit(0);
	return (0);
}
