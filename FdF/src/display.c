/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:23:35 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/28 17:26:15 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	display_parsed(t_vector **map, t_dim dims)
{
	int	pos1;
	int	pos2;

	pos1 = 0;
	while (pos1 < dims.height)
	{
		pos2 = 0;
		while (pos2 < dims.width)
		{
			ft_printf("%-3d ", map[pos1][pos2].z);
			pos2++;
		}
		ft_printf("\n");
		pos1++;
	}
}

void	displaypos_parsed(t_vector **map, t_dim dims)
{
	int	pos1;
	int	pos2;

	pos1 = 0;
	while (pos1 < dims.height)
	{
		pos2 = 0;
		while (pos2 < dims.width)
		{
			ft_printf("[%-2d:%-2d]%-3d ", map[pos1][pos2].x,
				map[pos1][pos2].y, map[pos1][pos2].z);
			pos2++;
		}
		ft_printf("\n");
		pos1++;
	}
}
