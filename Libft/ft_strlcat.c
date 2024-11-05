/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:01:38 by marvin            #+#    #+#             */
/*   Updated: 2024/11/05 15:06:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *d, const char *s, size_t n)
{
	size_t	len;

	len = 0;
	while (*d++);
	while (*s && n)
	{
		*d = *s;
		s++;
		d++;
		n--;
		len++;
	}
	return (len);
}
