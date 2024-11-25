/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapcase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:55:52 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/25 12:59:46 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_swapcase(const char *s)
{
	char	*swapped;
	size_t	pos;

	swapped = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	pos = 0;
	while (*s)
	{
		if (ft_islower(*s))
			swapped[pos] = *s - 32;
		else if (ft_isupper(*s))
			swapped[pos] = *s +32;
		else
			swapped[pos] = *s;
		pos++;
		s++;
	}
	swapped[pos] = 0;
	return (swapped);
}
