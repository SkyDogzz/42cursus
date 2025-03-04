/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:24:32 by marvin            #+#    #+#             */
/*   Updated: 2024/11/25 23:33:55 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			pos;
	unsigned char	*suc;
	unsigned char	uc;

	pos = 0;
	suc = (unsigned char *) s;
	uc = (unsigned char) c;
	while (pos < n)
	{
		if (*suc == uc)
			return ((void *)suc);
		suc++;
		pos++;
	}
	return (NULL);
}
