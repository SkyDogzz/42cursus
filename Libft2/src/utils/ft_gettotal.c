/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettotal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:03:21 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/26 17:08:23 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_gettotal(const int *tab, size_t len)
{
	int	total;

	total = 0;
	while (len > 0)
		total += tab[len-- - 1];
	return (total);
}
