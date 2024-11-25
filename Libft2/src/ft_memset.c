/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:00:04 by marvin            #+#    #+#             */
/*   Updated: 2024/11/06 14:19:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			pos;
	unsigned char	*suc;

	pos = 0;
	suc = (unsigned char *) s;
	while (pos < n)
	{
		suc[pos] = c;
		pos++;
	}
	return (s);
}
