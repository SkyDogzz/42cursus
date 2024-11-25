/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:46:08 by marvin            #+#    #+#             */
/*   Updated: 2024/11/09 16:29:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	char	*p;

	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	p = join;
	if (!join)
		return (NULL);
	while (*s1)
	{
		*join++ = *s1;
		s1++;
	}
	while (*s2)
	{
		*join++ = *s2;
		s2++;
	}
	*join = 0;
	return (p);
}
