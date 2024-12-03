/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 02:17:59 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/02 17:31:54 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

#define MULT 40

void	display_map(t_mlx data, t_map map)
{
	t_2vec pos;
	for (int x = 0; x < map.dims.width; x++)
		for (int y = 0; y < map.dims.height; y++)
		{
			pos.x = (( map.content[y][x].pos.x - (float) map.dims.width / 2) * MULT) + WINDOW_WIDTH / 2;
			pos.y = (( map.content[y][x].pos.y - (float) map.dims.height / 2) * MULT) + WINDOW_HEIGHT / 2;
			ft_printf("%d ");
			mlx_pixel_put(data.mlx_ptr, data.win_ptr, pos.x, pos.y, map.content[y][x].color);
		}
}
