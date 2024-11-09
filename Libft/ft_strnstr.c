/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:26:37 by marvin            #+#    #+#             */
/*   Updated: 2024/11/09 15:08:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	flag;
	int	pos;

	len -= ft_strlen(little) - 1;
	while (*big && len)
	{
		flag = 0;
		pos = 0;
		while (little[pos])
		{
			if (big[pos] != little[pos])
				flag++;
			pos++;
		}
		if (flag == 0)
			return ((char *) big);
		big++;
		len--;
	}
	return (NULL);
}
