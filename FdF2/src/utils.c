/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:25:55 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/04 13:15:41 by tstephan         ###   ########.fr       */
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
			ft_printf("[%d:%d] %d ", (int) map->content[pos.y][pos.x].pos.x,
				(int) map->content[pos.y][pos.x].pos.y,
				(int) map->content[pos.y][pos.x].pos.z);
			pos.x++;
		}
		ft_printf("\n");
		pos.y++;
	}
}
