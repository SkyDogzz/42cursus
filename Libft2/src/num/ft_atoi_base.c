/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:16:09 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/26 17:15:16 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static t_bool	ft_isbasevalid(const char *base)
{
	size_t	pos1;
	size_t	pos2;
	int		len;

	len = ft_strlen(base);
	if (len < 2 || len >= 36)
		return (FALSE);
	pos1 = 0;
	while (base[pos1])
	{
		if (!ft_isalnum(base[pos1]))
			return (FALSE);
		pos2 = pos1 + 1;
		while (base[pos2])
		{
			if (base[pos1] == base[pos2])
				return (FALSE);
			pos2++;
		}
		pos1++;
	}
	return (TRUE);
}

static int	ft_isinbase(const char c, const char *base)
{
	int	pos;

	pos = 0;
	while (base[pos])
	{
		if (base[pos] == c)
			return (pos);
		pos++;
	}
	return (-1);
}

int	ft_atoi_base(const char *s, const char *base)
{
	int		nbr;
	int		base_len;
	int		pos;
	t_bool	neg;

	if (!ft_isbasevalid(base))
		return (0);
	nbr = 0;
	base_len = ft_strlen(base);
	while (ft_isspace(*s))
		s++;
	neg = FALSE;
	if (*s == '-')
		neg = TRUE;
	pos = ft_isinbase(*s, base);
	while (pos >= 0)
	{
		nbr *= base_len;
		nbr += pos;
		pos = ft_isinbase(*s, base);
	}
	return (nbr * (neg * -1));
}
