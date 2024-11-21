/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:12:40 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/21 14:49:47 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlilen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != 0 && *s != '\n')
	{
		len++;
		s++;
	}
	if (*s == '\n')
		len++;
	return (len);
}

char	*ft_getmemory(char **s)
{
	char	*new;
	int		pos;

	new = (char *)malloc(sizeof(char) * (ft_strlilen(*s) + 1));
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

char	*get_next_line(int fd)
{
	static char	*memory = "test\navec\nplusieurs\nlignes";
	char		*current;

	current = ft_getmemory(&memory);
	if (current)
		return (current);
	return (NULL);
	(void) fd;
}
