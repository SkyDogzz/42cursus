/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:24:16 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/01 14:25:48 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

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

int atoi_base(const char *s, const char *base, const char *base2)
{
	int	nbr;
	int	pos;
	int	flag;
	ft_printf("atoi base %s\n", s);

	nbr = 0;
	while (*s)
	{
		pos = 0;
		flag = 0;
		while (base[pos] && base2[pos])
		{
			if (base[pos] == *s || base2[pos] == *s)
			{
				nbr *= ft_strlen(base);
				nbr += pos;
				flag = 1;
			}
			pos++;
		}
		if (flag == 0)
			return (nbr);
		s++;	
	}
	return (nbr);
}

int	get_color(const char *s)
{
	int	color = 0;
	while (ft_isdigit(*s))
		s++;
	if (*s != ',')
		return (color);
	color = atoi_base((s + 3), "0123456789abcdef", "0123456789ABCDEF");
	return (color);
}

void	fill_map(t_map *map, int fd)
{
	int		posx;
	int		posy;
	char	*line;
	char	*next;

	posy = 0;
	while (posy < map->dims.height)
	{
		line = get_next_line(fd);
		posx = 0;
		next = line;
		while (posx < map->dims.width)
		{
			while (*next == ' ' && posx < map->dims.width - 1)
				next++;
			map->content[posy][posx].height = ft_atoi(next);
			map->content[posy][posx].color = get_color(next);
			next = ft_strchr(next, ' ');
			posx++;
		}
		free(line);
		posy++;
	}
	line = get_next_line(fd);
	if (line)
		free(line);
}

void	print_map(t_map *map)
{
	int	posx;
	int	posy;

	posy = 0;
	while (posy < map->dims.height)
	{
		posx = 0;
		while (posx < map->dims.width)
		{
			/*printf("%d:%d %.1f %x ", posx, posy, map->content[posy][posx].height, map->content[posy][posx].color);*/
			ft_printf("%d ", (int) map->content[posy][posx].height);
			if (map->content[posy][posx].color)
				ft_printf("%p ", map->content[posy][posx].color);
			/*ft_printf("%d ", (int) map->content[posy][posx].height);*/
			posx++;
		}
		ft_printf("\n");
		posy++;
	}
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
	ft_printf("%d %d\n", map->dims.width, map->dims.height);
	map = init_map(map);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_msg_code("File not opened\n", 1);
	fill_map(map, fd);
	print_map(map);
	close(fd);
	return (map);
}
