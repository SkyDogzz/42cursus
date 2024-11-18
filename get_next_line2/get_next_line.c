/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:10:31 by marvin            #+#    #+#             */
/*   Updated: 2024/11/18 18:24:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int			readed;
	static char	*act;
	static char *next;
	(void) act;
	(void) next;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	readed = read(fd, buffer, BUFFER_SIZE);
	return (buffer);
}
