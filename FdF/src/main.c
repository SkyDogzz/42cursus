/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:53:31 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/28 18:04:09 by tstephan         ###   ########.fr       */
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

t_vector	**fill_map(t_vector **map, t_dim dims, int fd)
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
	map = fill_map(map, dims, fd);
	full_close(fd);
	return (map);
}

int	main(int argc, char *argv[])
{
	t_content	content;
	t_mlx		data;

	if (argc < 2)
	{
		ft_dprintf(2, "Usage: %s <input_file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	content.dims = get_dim(argv[1]);
	content.map = parse_map(argv[1], *content.dims);
	free_map(content.map, content.dims->height);
	free(content.dims);
	data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        return (MLX_ERROR);
    data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
            "My first window!");
    if (data.win_ptr == NULL)
    {
        free(data.win_ptr);
        return (MLX_ERROR);
    }
    mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
    mlx_key_hook(data.win_ptr, &handle_key, &data);
	mlx_mouse_hook(data.win_ptr, &handle_mouse, &data);
	mlx_hook(data.win_ptr, 17, 0, &full_quit, &data);
    mlx_loop(data.mlx_ptr);
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
