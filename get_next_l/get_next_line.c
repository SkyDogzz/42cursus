/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:12:40 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/21 17:38:37 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strclen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != 0 && *s != c)
	{
		len++;
		s++;
	}
	if (*s != 0 && *s == c)
		len++;
	return (len);
}

char	*ft_getmemory(char **s)
{
	char	*new;
	int		pos;

	if (!**s)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strclen(*s, '\n') + 1));
	pos = 0;
	while (**s != 0 && **s != '\n')
	{
		new[pos++] = **s;
		(*s)++;
	}
	if (**s == '\n')
	{
		new[pos++] = '\n';
		(*s)++;
	}
	new[pos] = 0;
	return (new);
}

char	*ft_strchrnn(const char *s)
{
	char	*memory;
	int		pos;

	memory = (char *)malloc(sizeof(char) * ft_strclen(s, 0));
	pos = 0;
	while (*s && *s != '\n')
		s++;
	if (*s == '\n')
		s++;
	while (*s)
		memory[pos++] = *s++;
	if (pos == 0)
		return (NULL);
	return (memory);
}

char	*ft_appendton(char *dest, char *src)
{
	char	*new;
	int		pos;

	printf("here %s %d\n", dest, !dest);
	if (!dest || dest == NULL)
	{
		new = (char *)malloc(sizeof(char) * (ft_strclen(src, '\n') + 1));
		pos = 0;
		while (*src && *src != '\n')
			new[pos++] = *src++;
		if (*src == '\n')
			new[pos++] = '\n';
		new[pos] = 0;
		return (new);
	}
	new = (char *)malloc(sizeof(char) * (ft_strclen(dest, 0) + ft_strclen(src, '\n') + 1));
	pos = 0;
	while (*dest)
		new[pos++] = *dest++;
	while (*src && *src != '\n')
		new[pos++] = *src++;
	if (*src == '\n')
		new[pos++] = '\n';
	new[pos] = 0;
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*current;
	char		*buffer;

	if (memory)
	{
		current = ft_getmemory(&memory);
		if (current)
			return (current);
	}
	memory = NULL;
	current = NULL;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (!memory)
	{
		read(fd, buffer, BUFFER_SIZE);
		current = ft_appendton(current, buffer);
		memory = ft_strchrnn(buffer);
		usleep(1000000);
	}
	return (current);
}
