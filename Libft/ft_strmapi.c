/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:12:25 by marvin            #+#    #+#             */
/*   Updated: 2024/11/09 10:22:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		pos;
	char	*mapped;

	mapped = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!mapped)
		return (NULL);
	pos = 0;
	while (*s)
	{
		mapped[pos] = f(pos, s[pos]);
		pos++;
	}
	return (mapped);
}
