/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 23:16:13 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/28 16:11:01 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

char	*ft_strchr2(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

t_fd_node	*get_fd_node(t_fd_node **fd_list, int fd)
{
	t_fd_node	*current;

	current = *fd_list;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	current = (t_fd_node *)malloc(sizeof(t_fd_node));
	if (!current)
		return (NULL);
	current->fd = fd;
	current->store = NULL;
	current->next = *fd_list;
	*fd_list = current;
	return (current);
}

void	remove_fd_node(t_fd_node **fd_list, int fd)
{
	t_fd_node	*current;
	t_fd_node	*prev;

	current = *fd_list;
	prev = NULL;
	while (current)
	{
		if (current->fd == fd)
		{
			if (prev)
				prev->next = current->next;
			else
				*fd_list = current->next;
			free(current->store);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void	full_close(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return ;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
