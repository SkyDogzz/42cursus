/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:39:07 by marvin            #+#    #+#             */
/*   Updated: 2024/11/10 12:35:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd)
{
	int		pos;
	char	c;
	char	*buffer;

	pos = 0;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	while (read(fd, &c, 1) != 0)
	{
		buffer[pos] = c;
		if (c == '\n')
		{
			buffer[pos] = '\n';
			return (buffer);
		}
		pos++;
	}
	return (buffer);
}

int main(void)
{
	static int		fd;
	char	*buffer;

	fd = open("test", O_RDONLY, "r");
	buffer = get_next_line(fd);
	printf("%lu %s", strlen(buffer), buffer);

	return EXIT_SUCCESS;
}
