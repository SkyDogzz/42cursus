/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:51:10 by marvin            #+#    #+#             */
/*   Updated: 2024/11/20 23:09:47 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_memoverlap(void *p1, void *p2, size_t n)
{
	if (p1 < p2 && p1 + sizeof(char) * n > p2)
		return (1);
	else if (p2 < p1 && p2 + sizeof(char) * n > p1)
		return (-1);
	return (0);
}

static void	*ft_memcpyrev(void *dest, const void *src, size_t n)
{
	unsigned char	*destuc;
	unsigned char	*srcuc;

	destuc = (unsigned char *) dest;
	srcuc = (unsigned char *) src;
	while (n > 0)
	{
		destuc[n - 1] = srcuc[n - 1];
		n--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t	n)
{
	int	over;

	over = ft_memoverlap(dest, (void *) src, n);
	if (over == 0 || over == 1)
		ft_memcpy(dest, src, n);
	else
		ft_memcpyrev(dest, src, n);
	return (dest);
}
