/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:51:19 by marvin            #+#    #+#             */
/*   Updated: 2024/11/25 23:31:48 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total_size;
	unsigned char	*p;
	size_t			pos;

	if (nmemb == 0 || size == 0)
	{
		p = (unsigned char *)malloc(1);
		if (!p)
			return (NULL);
		return (p);
	}
	total_size = nmemb * size;
	if (total_size / nmemb != size)
		return (NULL);
	p = (unsigned char *)malloc(total_size);
	if (!p)
		return (NULL);
	pos = 0;
	while (pos < total_size)
		p[pos++] = 0;
	return ((void *)p);
}
