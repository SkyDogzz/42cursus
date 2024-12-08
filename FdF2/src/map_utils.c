/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:09:17 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/08 17:28:02 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_map_full(t_map *map)
{
	while (map->dims.height--)
	{
		free(map->content[map->dims.height]);
	}
	free(map->content);
	free(map);
}

void	setup_map(t_wrapper *wrapper)
{
	wrapper->map->offset.x = 0;
	wrapper->map->offset.y = 0;
	wrapper->map->helper = HELPER;
	wrapper->offset_div = OFFSET_DIV;
}

t_map	*init_map(t_map *map)
{
	int	pos;

	map->height_div = HEIGHT_DIV;
	map->content = (t_cont **)malloc(sizeof(t_cont *) * map->dims.height);
	if (!map->content)
		return (NULL);
	pos = 0;
	while (pos < map->dims.height)
	{
		map->content[pos] = (t_cont *)malloc(sizeof(t_cont) * map->dims.width);
		if (!map->content[pos])
		{
			free_map_content(map, pos);
			return (NULL);
		}
		pos++;
	}
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

void	free_map_content(t_map *map, int pos)
{
	pos--;
	while (pos >= 0)
	{
		free(map->content[pos]);
		pos--;
	}
	free(map->content);
}
