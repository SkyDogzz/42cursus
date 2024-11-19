/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:10:31 by marvin            #+#    #+#             */
/*   Updated: 2024/11/19 12:12:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*buffer;
	int		readed;
	int		size;
	char	*act;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	size = ft_strlinelen(buffer);
	act = (char *)malloc(sizeof(char) * (size + 1));
	readed = read(fd, buffer, BUFFER_SIZE);
	ft_strlinecat(act, buffer);
	return (act);
}
