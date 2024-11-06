/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:26:37 by marvin            #+#    #+#             */
/*   Updated: 2024/11/06 12:21:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strnstr(const char *big, const char *little, size_t len)
{
	int	flag;
	int	pos;

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
