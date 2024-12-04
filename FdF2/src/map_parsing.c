/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:15:25 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/04 15:41:37 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	fill_point(t_map *map, t_2vec pos, char **next, t_dim dims)
{
	map->content[pos.y][pos.x].pos.x = pos.x - dims.width / 2.0 + 0.5;
	map->content[pos.y][pos.x].pos.y = pos.y - dims.height / 2.0 + 0.5;
	map->content[pos.y][pos.x].pos.z = ft_atoi(*next) / map->height_div;
	map->content[pos.y][pos.x].color = get_color(*next);
	*next = ft_strchr(*next, ' ');
}

void	process_line(t_map *map, char *line, int y, t_dim dims)
{
	t_2vec	pos;
	char	*next;

	pos.y = y;
	pos.x = 0;
	next = line;
	while (pos.x < dims.width)
	{
		while (*next == ' ' && pos.x < dims.width)
			next++;
		fill_point(map, pos, &next, dims);
		pos.x++;
	}
}

void	fill_map(t_map *map, int fd)
{
	t_dim	dims;
	char	*line;
	int		y;

	dims = map->dims;
	y = 0;
	while (y < dims.height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		process_line(map, line, y, dims);
		free(line);
		y++;
	}
	line = get_next_line(fd);
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
	map->zoom = WINDOW_WIDTH / min(map->dims.height, map->dims.width) * ZOOM;
	map = init_map(map);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_msg_code("File not opened\n", 1);
	fill_map(map, fd);
	close(fd);
	return (map);
}

int	get_width(const char *line)
{
	int	width;

	width = 0;
	if (*line++ != ' ')
		width++;
	while (*line)
	{
		if (*line != ' ' && *(line - 1) == ' ' && *line != '\n')
			width++;
		line++;
	}
	return (width);
}
