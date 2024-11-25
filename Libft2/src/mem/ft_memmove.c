/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:51:10 by marvin            #+#    #+#             */
/*   Updated: 2024/11/25 23:34:08 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	ft_memoverlap(void *p1, void *p2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (unsigned char *)p1;
	ptr2 = (unsigned char *)p2;
	if (ptr1 < ptr2 && ptr1 + n > ptr2)
		return (1);
	else if (ptr2 < ptr1 && ptr2 + n > ptr1)
		return (-1);
	return (0);
}

static void	*ft_memcpyrev(void *dest, const void *src, size_t n)
{
	unsigned char		*destuc;
	const unsigned char	*srcuc;

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
