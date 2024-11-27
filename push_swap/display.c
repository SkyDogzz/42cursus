/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:15:31 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/27 15:32:12 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_displaypile(t_number *pile, size_t n)
{
	size_t	pos;

	pos = 0;
	while (pos < n)
	{
		ft_printf("%d ", pile[pos].number);
		pos++;
	}
}

void	ft_displaypileindice(t_number *pile, size_t n)
{
	size_t	pos;

	pos = 0;
	while (pos < n)
	{
		ft_printf("%d|%d ", pile[pos].number, pile[pos].indice);
		pos++;
	}
}
