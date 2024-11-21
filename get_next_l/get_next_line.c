/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:12:40 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/21 18:00:42 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strclen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != 0 && s[len] != c)
		len++;
	if (s[len] == c)
		len++;
	return (len);
}

char	*ft_getmemory(char **s)
{
	char	*new;
	int		pos;
	char	*temp;

	if (!**s)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strclen(*s, '\n') + 1));
	if (!new)
		return (NULL);
	pos = 0;
	temp = *s;
	while (*temp != 0 && *temp != '\n')
		new[pos++] = *temp++;
	if (*temp == '\n')
		new[pos++] = *temp++;
	new[pos] = 0;
	*s = temp;
	return (new);
}

char	*ft_strchrnn(const char *s)
{
	char	*memory;
	int		pos;
	int		len;

	while (*s && *s != '\n')
		s++;
	if (*s == '\n')
		s++;
	len = ft_strclen(s, '\n');
	memory = (char *)malloc(sizeof(char) * (len + 1));
	if (!memory)
		return (NULL);
	pos = 0;
	while (*s)
		memory[pos++] = *s++;
	memory[pos] = 0;
	return (memory);
}

char	*ft_appendton(char *dest, char *src)
{
	char	*new;
	int		pos;
	int		i;

	if (!src)
		return (dest);
	if (!dest || dest == NULL)
	{
		new = (char *)malloc(sizeof(char) * (ft_strclen(src, '\n') + 1));
		if (!new)
			return (NULL);
		pos = 0;
		while (src[pos] && src[pos] != '\n')
		{
			new[pos] = src[pos];
			pos++;
		}
		if (src[pos] == '\n')
			new[pos++] = '\n';
		new[pos] = 0;
		return (new);
	}
	new = (char *)malloc(sizeof(char) * (ft_strclen(dest, 0)
				+ ft_strclen(src, '\n') + 1));
	if (!new)
		return (NULL);
	pos = 0;
	i = 0;
	while (dest[i])
		new[pos++] = dest[i++];
	i = 0;
	while (src[1] != '\n')
		new[pos++] = src[i++];
	if (*src == '\n')
		new[pos++] = '\n';
	new[pos] = 0;
	free(dest);
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
	}
	return (current);
}
