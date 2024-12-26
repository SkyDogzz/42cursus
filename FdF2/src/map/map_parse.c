/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:00:00 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/26 10:57:13 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	get_width(const char *line)
{
	int	width;
	int	i;

	width = 0;
	i = 0;
	if (!line || !(*line))
		return (0);
	if (line[i] != ' ' && line[i] != '\n')
		width++;
	i++;
	while (line[i])
	{
		if (line[i] != ' '
			&& line[i] != '\n'
			&& line[i - 1] == ' ')
			width++;
		i++;
	}
	return (width);
}

int	get_height(int fd)
{
	int		height;
	char	*line;

	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (height);
}

void	verif_map(const t_map *map)
{
	if (map->dims.height <= 0 || map->dims.width <= 0)
		exit_msg_code("Either width or height not correct\n", 1);
	ft_printf("Map: Parsed\n");
	ft_printf("Height %d Width %d\n", map->dims.height, map->dims.width);
}

t_map	*parse_map(const char *filename)
{
	t_map	*map;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_msg_code("File not opened\n", 1);
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		exit_msg_code("Allocation error\n", 1);
	line = get_next_line(fd);
	map->dims.width = get_width(line);
	free(line);
	map->dims.height = 1 + get_height(fd);
	map->zoom = (float)WINDOW_WIDTH
		/ ft_min_float(map->dims.height, map->dims.width) * ZOOM;
	map->height_div = HEIGHT_DIV;
	map->filename = ft_strdup(filename);
	close(fd);
	map = init_map(map);
	fd = open(filename, O_RDONLY);
	fill_map(map, fd);
	verif_map(map);
	close(fd);
	return (map);
}

void	fill_map(t_map *map, int fd)
{
	int		y;
	t_dim	d;
	char	*line;

	y = 0;
	d = map->dims;
	while (y < d.height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		process_line(map, line, y, d);
		free(line);
		y++;
	}
}
