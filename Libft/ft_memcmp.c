/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:29:00 by marvin            #+#    #+#             */
/*   Updated: 2024/11/06 14:34:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1uc;
	unsigned char	*s2uc;

	s1uc = (unsigned char *) s1;
	s2uc = (unsigned char *) s2;
	while (n)
	{
		if (*s1uc != *s2uc)
			return (*s1uc - *s2uc);
		s1uc++;
		s2uc++;
		n--;
	}
	return (0);
}
