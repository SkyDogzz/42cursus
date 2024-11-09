/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:24:32 by marvin            #+#    #+#             */
/*   Updated: 2024/11/09 15:41:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				pos;
	unsigned char	*suc;

	pos = 0;
	suc = (unsigned char *) s;
	while (pos < n)
	{
		if (*suc == c)
			return ((void *)(s + pos));
		suc++;
		pos++;
	}
	return (NULL);
}
