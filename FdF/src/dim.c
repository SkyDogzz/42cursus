/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:36:31 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/28 01:38:52 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_dim	*get_dim(const char *filename)
{
	int		fd;
	t_dim	*dims;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_dprintf(2, "Error opening file: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	dims = (t_dim *)malloc(sizeof(t_dim) * 1);
	line = get_next_line(fd);
	if (!dims || !line)
		return (NULL);
	dims->width = ft_countwords(line, ' ');
	dims->height = 0;
	while (line)
	{
		free(line);
		dims->height++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (dims);
}
