/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:44:24 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/28 19:51:56 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	projection(t_3vector p3d, t_2vector *p2d, float focal)
{
	if (p3d.z == 0)
		p3d.z = 0.1;
	p2d->x = (int)((focal * p3d.x) / p3d.z);
	p2d->y = (int)((focal * p3d.y) / p3d.z);
}
