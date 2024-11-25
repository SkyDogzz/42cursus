/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:34:46 by marvin            #+#    #+#             */
/*   Updated: 2024/11/19 12:56:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			pos;
	unsigned char	*destuc;
	unsigned char	*srcuc;

	if (n > 0 && !dest && !src)
		return (NULL);
	pos = 0;
	destuc = (unsigned char *) dest;
	srcuc = (unsigned char *) src;
	while (pos < n)
	{
		destuc[pos] = srcuc[pos];
		pos++;
	}
	return (dest);
}
