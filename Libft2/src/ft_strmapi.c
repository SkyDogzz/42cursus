/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:12:25 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 23:32:59 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	pos;
	char			*mapped;

	if (!s || !f)
		return (NULL);
	mapped = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!mapped)
		return (NULL);
	pos = 0;
	while (s[pos])
	{
		mapped[pos] = f(pos, s[pos]);
		pos++;
	}
	mapped[pos] = '\0';
	return (mapped);
}
