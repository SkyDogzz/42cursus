/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:58:50 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 23:16:11 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *d, const char *s, size_t n)
{
	size_t		len;
	const char	*s_start = s;

	len = 0;
	while (*s++)
		len++;
	s = s_start;
	if (n > 0)
	{
		while (*s && n > 1)
		{
			*d++ = *s++;
			n--;
		}
		*d = '\0';
	}
	return (len);
}
