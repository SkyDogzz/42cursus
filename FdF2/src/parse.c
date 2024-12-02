/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:24:16 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/02 02:15:25 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_height(int fd)
{
	int		height;
	char	*line;

	height = 1;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	free(line);
	return (height);
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

t_map	*init_map(t_map *map)
{
	int	pos;

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

void	fill_map(t_map *map, int fd)
{
	t_2vec		pos;
	char		*line;
	char		*next;

	pos.y = 0;
	while (pos.y < map->dims.height)
	{
		line = get_next_line(fd);
		pos.x = 0;
		next = line;
		while (pos.x < map->dims.width)
		{
			while (*next == ' ' && pos.x < map->dims.width - 1)
				next++;
			map->content[pos.y][pos.x].height = ft_atoi(next);
			map->content[pos.y][pos.x].color = get_color(next);
			next = ft_strchr(next, ' ');
			pos.x++;
		}
		free(line);
		pos.y++;
	}
	line = get_next_line(fd);
	if (line)
		free(line);
}

t_map	*parse_map(const char *filename)
{
	int		fd;
	t_map	*map;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_msg_code("File not opened\n", 1);
	map = (t_map *)malloc(sizeof(t_map) * 1);
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	map->dims.width = get_width(line);
	free(line);
	map->dims.height = get_height(fd);
	map = init_map(map);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_msg_code("File not opened\n", 1);
	fill_map(map, fd);
	close(fd);
	return (map);
}
