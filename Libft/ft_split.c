/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:16:02 by marvin            #+#    #+#             */
/*   Updated: 2024/11/06 16:42:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(const char *s, char c)
{
	int	words;

	words = 0;
	s++;
	while (*s)
	{
		if (*(s - 1) != c && *s == c)
			words++;
		s++;
	}
	if (*--s == c)
		words--;
	return (words);
}

char	**ft_split(const char *s, char c)
{
	int		j;
	int		pos;
	int		words;
	char	**split;

	words = ft_countwords(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	pos = 0;
	while (pos < words)
	{
		j = 0;
		while (*s++ != c)
			j++;
		s -= j;
		*split = (char *)malloc(sizeof(char) * (j + 1));
		while (*s++ != c)
			*split[pos]++ = *s++;
		*split[pos] = 0;
		pos++;
	}
	split[pos] = 0;
	return (split);
}
