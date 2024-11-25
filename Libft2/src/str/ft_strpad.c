/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:23:06 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/25 19:14:14 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strpad(const char *s, char pad, size_t len, int left)
{
	char	*padded;
	size_t	pos;

	padded = (char *)malloc(sizeof(char) * (ft_strlen(s) + len + 1));
	pos = 0;
	if (left)
	{
		while (len--)
			padded[pos++] = pad;
		while (*s)
			padded[pos++] = *s++;
		padded[pos] = 0;
	}
	else
	{
		while (*s)
			padded[pos++] = *s++;
		while (len--)
			padded[pos++] = pad;
		padded[pos] = 0;
	}
	return (padded);
}
