/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:10:44 by marvin            #+#    #+#             */
/*   Updated: 2024/11/19 12:16:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlinecat(char *d, const char *s)
{
	int	eol;

	eol = 0;
	while (*d)
		d++;
	while (*s && *s != '\n')
		*d++ = *s++;
	if (*s == '\n')
	{
		*d++ = '\n';
		eol = 1;
	}
	*d = 0;

	return (eol);
}

size_t	ft_strlinelen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s && *s != '\n')
		len++;
	if (*s == '\n')
		len++;
	return (len);
}
