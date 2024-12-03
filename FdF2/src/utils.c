/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:25:55 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/03 13:24:09 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	exit_msg_code(const char *message, int code)
{
	ft_dprintf(2, "%s", message);
	exit(code);
}

void	print_map(t_map *map)
{
	t_2vec	pos;

	pos.y = 0;
	while (pos.y < map->dims.height)
	{
		pos.x = 0;
		while (pos.x < map->dims.width)
		{
			// ft_printf("%d ", (int) map->content[pos.y][pos.x].pos.z);
			// if (map->content[pos.y][pos.x].color)
			// 	ft_printf("%p ", map->content[pos.y][pos.x].color);
			printf("[%.1f:%.1f] %.1f ", map->content[pos.y][pos.x].pos.x, map->content[pos.y][pos.x].pos.y, map->content[pos.y][pos.x].pos.z);
			pos.x++;
		}
		printf("\n");
		pos.y++;
	}
}
