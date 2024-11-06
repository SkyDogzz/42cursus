/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:52:02 by marvin            #+#    #+#             */
/*   Updated: 2024/11/06 16:30:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countsetend(const char *s, const char *set)
{
	int	n;
	int	pos;
	int	posset;
	int	flag;

	n = 0;
	pos = ft_strlen(s);
	while (*(s + pos))
	{
		posset = 0;
		flag = 0;
		while (*(set + posset))
		{
			if (*(s + pos) == *(set + posset))
			{
				flag = 1;
				n++;
			}
			posset++;
		}
		if (flag == 0)
			return (n);
		pos--;
	}
	return (n);
}

int	ft_countsetstart(const char *s, const char *set)
{
	int	n;
	int	flag;
	int	posset;

	n = 0;
	while (*s)
	{
		posset = 0;
		flag = 0;
		while (*(set + posset))
		{
			if (*s == *(set + posset))
			{
				flag = 1;
				n++;
			}
			posset++;
		}
		if (flag == 0)
			return (n);
		s++;
	}
	return (n);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		posttrim;
	int		pretrim;
	int		pos;
	int		len;
	char	*trim;

	posttrim = ft_countsetend(s1, set);
	pretrim = ft_countsetstart(s1, set);
	while (pretrim--)
		s1++;
	pos = 0;
	len = ft_strlen(s1) - pretrim - posttrim;
	trim = (char *)malloc(sizeof(char) * (len + 1));
	if (!trim)
		return (NULL);
	while (len)
	{
		*(trim + pos++) = *s1++;
		len--;
	}
	*(trim + pos) = 0;
	return (trim);
}
