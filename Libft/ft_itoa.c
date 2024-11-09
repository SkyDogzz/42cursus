/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 09:52:57 by marvin            #+#    #+#             */
/*   Updated: 2024/11/09 17:37:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	char	*rev;
	char	temp;
	int		size;
	int		pos;

	size = ft_strlen(s);
	if (size == 0)
		return ("0");
	rev = (char *)malloc(sizeof(char) * (size + 1));
	if (!rev)
		return (NULL);
	pos = 0;
	rev[size] = 0;
	while (size)
		rev[size-- - 1] = s[pos++];
	if (!rev)
		return ("0");
	return (rev);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		pos;
	int		neg;

	if (n == -2147483648)
		return ("-2147483648");
	num = (char *)malloc(sizeof(char) * 12);
	if (!num)
		return (NULL);
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	pos = 0;
	while (n)
	{
		num[pos++] = n % 10 + '0';
		n /= 10;
	}
	if (neg)
		num[pos++] = '-';
	num[pos] = 0;
	return (ft_strrev(num));
}
