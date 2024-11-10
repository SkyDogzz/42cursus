/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:38:49 by marvin            #+#    #+#             */
/*   Updated: 2024/11/10 16:05:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isflag(char c)
{
	char	*set;

	set = (char *)malloc(sizeof(char) * 4);
	ft_strlcpy(set, "# +", 3);
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

void	ft_store_flag(int *flag, char c)
{
	int		pos;
	char	*set;

	set = (char *)malloc(sizeof(char) * 4);
	ft_strlcpy(set, "# +", 3);
	pos = 0;
	while (set[pos])
	{
		if (set[pos] == c)
		{
			if (*flag && (1 << pos))
				return ;
			*flag += (1 << pos);
			return ;
		}
		pos++;
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		flag;

	va_start(ap, s);
	while (*s) {
		if (*s == '%')
		{
			s++;
			flag = 0;
			while (ft_isflag(*s))
			{
				ft_store_flag(&flag, *s);
				s++;
			}
			printf("\n flags = %d\n", flag);
		}
		else write(STDOUT_FILENO, s, 1);
		s++;
	}

	return (0);
}
