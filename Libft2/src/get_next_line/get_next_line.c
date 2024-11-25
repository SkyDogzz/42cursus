/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:12:40 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/25 23:40:26 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

static char	*read_and_store(int fd, char *store)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	ssize_t	bytes_read;

	bytes_read = 1;
	while (!ft_strchr(store, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buffer[bytes_read] = '\0';
		if (!store)
		{
			store = (char *)malloc(1);
			store[0] = '\0';
		}
		temp = ft_strjoin(store, buffer);
		free(store);
		if (!temp)
			return (NULL);
		store = temp;
	}
	return (store);
}

static char	*extract_line(const char *store)
{
	char	*line;
	size_t	i;

	if (!store || !*store)
		return (NULL);
	i = 0;
	while (store[i] && store[i] != '\n')
		i++;
	if (store[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (i--)
		line[i] = store[i];
	return (line);
}

static char	*save_remaining(char *store)
{
	char	*remaining;
	size_t	i;
	size_t	j;

	i = 0;
	while (store[i] && store[i] != '\n')
		i++;
	if (!store[i])
	{
		free(store);
		return (NULL);
	}
	remaining = (char *)malloc(sizeof(char) * (ft_strlen(store) - i));
	if (!remaining)
	{
		free(store);
		return (NULL);
	}
	i++;
	j = 0;
	while (store[i])
		remaining[j++] = store[i++];
	remaining[j] = '\0';
	free(store);
	return (remaining);
}

char	*get_next_line(int fd)
{
	static t_fd_node	*fd_list;
	t_fd_node			*node;
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = get_fd_node(&fd_list, fd);
	if (!node)
		return (NULL);
	node->store = read_and_store(fd, node->store);
	if (!node->store)
	{
		remove_fd_node(&fd_list, fd);
		return (NULL);
	}
	line = extract_line(node->store);
	node->store = save_remaining(node->store);
	if (!node->store)
		remove_fd_node(&fd_list, fd);
	return (line);
}
