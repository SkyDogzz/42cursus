/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:16:02 by marvin            #+#    #+#             */
/*   Updated: 2024/11/20 23:10:51 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_strndup(const char *s, int n)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static void	free_split(char **split, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(split[i++]);
	}
	free(split);
}

static char	*get_next_word(const char **s, char c)
{
	int	len;

	while (**s && **s == c)
		(*s)++;
	len = 0;
	while ((*s)[len] && (*s)[len] != c)
		len++;
	return (ft_strndup(*s, len));
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < words)
	{
		split[i] = get_next_word(&s, c);
		if (!split[i])
		{
			free_split(split, i);
			return (NULL);
		}
		s += ft_strlen(split[i]);
		i++;
	}
	split[i] = NULL;
	return (split);
}
