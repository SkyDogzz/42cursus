/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:51:19 by marvin            #+#    #+#             */
/*   Updated: 2024/11/09 16:37:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	int				pos;
	int				result;
	unsigned char	*p;

	if (nmemb == 0 || size == 0)
		return ((void *)malloc(sizeof(void) * 1));
	result = nmemb * (int)size;
	if (nmemb != result / size)
		return (NULL);
	p = (unsigned char *)malloc(sizeof(unsigned char) * size * nmemb);
	pos = 0;
	while (pos < size)
		p[pos++] = 0;
	return ((void *) p);
}
