/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:12:14 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/28 18:51:10 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_3vector	**init_map(t_dim dims)
{
	int			pos;
	t_3vector	**map;

	map = (t_3vector **)malloc(sizeof(t_3vector *) * dims.height);
	if (!map)
		return (NULL);
	pos = 0;
	while (pos < dims.height)
	{
		map[pos] = (t_3vector *)malloc(sizeof(t_3vector) * dims.width);
		if (!map[pos])
		{
			free_map(map, pos);
			return (NULL);
		}
		pos++;
	}
	return (map);
}

t_3vector	**fill_map(t_3vector **map, t_dim dims, int fd)
{
	int			pos1;
	int			pos2;
	char		*line;
	char		*next;

	pos1 = 0;
	while (pos1 < dims.height)
	{
		line = get_next_line(fd);
		next = line;
		pos2 = 0;
		while (pos2 < dims.width)
		{
			map[pos1][pos2].y = pos1;
			map[pos1][pos2].x = pos2;
			map[pos1][pos2].z = ft_atoi(next);
			while (*next == ' ')
				next++;
			next = strchr(next, ' ') + sizeof(char) * 1;
			pos2++;
		}
		free(line);
		pos1++;
	}
	return (map);
}

t_3vector	**parse_map(const char *filename, t_dim dims)
{
	int			fd;
	t_3vector	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_dprintf(2, "Error opening file: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	map = init_map(dims);
	map = fill_map(map, dims, fd);
	full_close(fd);
	return (map);
}
