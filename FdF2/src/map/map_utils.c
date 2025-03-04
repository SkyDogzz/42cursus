/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:00:00 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/26 11:24:26 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_map	*init_map(t_map *map)
{
	map->content = (t_cont *)malloc(sizeof(t_cont)
			* map->dims.width * map->dims.height);
	if (!map->content)
		exit_msg_code("Allocation error\n", 1);
	return (map);
}

int	forbidden_char(const char *s)
{
	char	*charset;
	int		pos;
	int		find;

	charset = ft_strdup(" ,-xXabcdefABCDEF0123456789\n");
	while (*s)
	{
		pos = 0;
		find = 0;
		while (charset[pos])
		{
			if (charset[pos] == *s)
				find = 1;
			pos++;
		}
		if (find == 0)
			return (1);
		s++;
	}
	free(charset);
	return (0);
}

void	process_line(t_map *map, char *line, int y, t_dim dims)
{
	t_2vec	p;
	char	*next;

	p.y = y;
	p.x = 0;
	next = line;
	if (forbidden_char(line))
	{
		exit_msg_code(ft_strjoin("Could not parse line\n", line), 1);
	}
	while (p.x < dims.width)
	{
		while (*next == ' ')
			next++;
		fill_point(map, p, &next, dims);
		p.x++;
	}
}

void	fill_point(t_map *map, t_2vec p, char **next, t_dim dims)
{
	int	index;

	index = p.y * dims.width + p.x;
	map->content[index].pos.x = p.x - dims.width / 2.0f + 0.5f;
	map->content[index].pos.y = p.y - dims.height / 2.0f + 0.5f;
	map->content[index].pos.z = (float)ft_atoi(*next) / map->height_div;
	map->content[index].color = get_color(*next);
	while (**next && **next != ' ')
		(*next)++;
}

void	free_map_full(t_map *map)
{
	if (map->content)
		free(map->content);
	if (map->filename)
		free(map->filename);
	free(map);
}
