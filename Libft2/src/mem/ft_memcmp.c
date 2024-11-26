/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:29:00 by marvin            #+#    #+#             */
/*   Updated: 2024/11/26 17:11:11 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1uc;
	const unsigned char	*s2uc;

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
