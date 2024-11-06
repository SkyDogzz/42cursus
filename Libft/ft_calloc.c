/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:51:19 by marvin            #+#    #+#             */
/*   Updated: 2024/11/06 16:31:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	int				pos;
	long long		result;
	unsigned char	*p;

	if (nmemb == 0 || size == 0)
		return (NULL);
	result = nmemb * size;
	if (nmemb != result / size)
		return (NULL);
	p = (unsigned char *)malloc(sizeof(unsigned char) * size);
	pos = 0;
	while (pos < size)
		p[pos++] = 0;
	return ((void *) p);
}
