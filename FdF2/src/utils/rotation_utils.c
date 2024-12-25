/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:00:00 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/25 16:16:07 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	rotate(t_wrapper *wrapper)
{
	float	angle;

	angle = (float)M_PI / wrapper->rotate_div;
	if (inlist(wrapper->keys, SHIFT_CODE))
		angle = -angle;
	if (inlist(wrapper->keys, X_CODE))
		rotatex_map(wrapper->map, angle);
	if (inlist(wrapper->keys, Y_CODE))
		rotatey_map(wrapper->map, angle);
	if (inlist(wrapper->keys, Z_CODE))
		rotatez_map(wrapper->map, angle);
	display_map(wrapper);
}

void	base_rotate(t_wrapper *wrapper)
{
	rotatex_map(wrapper->map, (float)M_PI / 32.0f * 10.0f);
	rotatey_map(wrapper->map, (float)M_PI / 32.0f * 7.0f);
	rotatez_map(wrapper->map, -(float)M_PI / 32.0f * 4.0f);
}
