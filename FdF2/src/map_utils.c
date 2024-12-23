/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:09:17 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/23 17:53:38 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_map_full(t_map *map)
{
	free(map->content);
	free(map);
}

void	setup_map(t_wrapper *wrapper)
{
	wrapper->map->offset.x = 0;
	wrapper->map->offset.y = 0;
	wrapper->map->helper = HELPER;
	wrapper->offset_div = OFFSET_DIV;
	wrapper->rotate_div = ROTATE_DIV;
}

t_map	*init_map(t_map *map)
{
	map->height_div = HEIGHT_DIV;
	map->content = malloc(sizeof(t_cont) * (map->dims.width
				* map->dims.height));
	if (!map->content)
		exit_msg_code("Allocation error\n", 1);
	return (map);
}

void	refill_map(t_wrapper *wrapper)
{
	int	fd;

	fd = open(wrapper->map->filename, O_RDONLY);
	if (fd == -1)
		exit_msg_code("File not opened\n", 1);
	fill_map(wrapper->map, fd);
	close(fd);
}
