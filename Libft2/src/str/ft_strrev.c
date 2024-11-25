/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:19:42 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/25 23:20:50 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strrev(const char *s)
{
	char	*rev;
	size_t	pos;

	rev = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	pos = ft_strlen(s);
	rev[pos--] = 0;
	while (pos > 0)
	{
		rev[pos] = *s++;
		pos--;
	}
	return (rev);
}
