/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:47:31 by marvin            #+#    #+#             */
/*   Updated: 2024/11/06 14:50:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		pos;
	char	*dup;

	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	pos = 0;
	while (*s)
	{
		*(dup + pos) = *s;
		s++;
		pos++;
	}
	*(dup + pos) = 0;
	return (dup);
}
