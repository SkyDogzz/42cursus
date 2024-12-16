/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:23:56 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/16 19:25:26 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlen(const char *str)
{
	const unsigned long long	*ptr;
	const char					*start = str;
	unsigned long long			chunk;

	ptr = (const unsigned long long *)str;
	while (1)
	{
		chunk = *ptr;
		if ((chunk - 0x0101010101010101ULL) & ~chunk & 0x8080808080808080ULL)
		{
			str = (const char *)ptr;
			while (*str)
				str++;
			return (str - start);
		}
		ptr++;
	}
}
