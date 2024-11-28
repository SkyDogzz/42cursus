/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:59:42 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/28 01:40:43 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_map(t_vector **map, int size)
{
	while (--size >= 0)
		free(map[size]);
	free(map);
}

t_vector	**init_map(t_dim dims)
{
	int			pos;
	t_vector	**map;

	map = (t_vector **)malloc(sizeof(t_vector *) * dims.height);
	if (!map)
		return (NULL);
	pos = 0;
	while (pos < dims.height)
	{
		map[pos] = (t_vector *)malloc(sizeof(t_vector) * dims.width);
		if (!map[pos])
		{
			free_map(map, pos);
			return (NULL);
		}
		pos++;
	}
	return (map);
}

t_vector	**parse_map(const char *filename, t_dim dims)
{
	int			fd;
	t_vector	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_dprintf(2, "Error opening file: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	map = init_map(dims);
	return (map);
}

int	main(int argc, char *argv[])
{
	t_vector	**map;
	t_dim		*dims;

	if (argc < 2)
	{
		ft_dprintf(2, "Usage: %s <input_file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	dims = get_dim(argv[1]);
	ft_printf("width = %d, height = %d\n", dims->width, dims->height);
	map = parse_map(argv[1], *dims);
	free_map(map, dims->height);
	free(dims);
	return (EXIT_SUCCESS);
}
