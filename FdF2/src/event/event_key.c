/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:00:00 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/25 16:11:38 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	handle_keypress(int keycode, t_wrapper *wrapper)
{
	add_key(&wrapper->keys, keycode);
	handle_misc(wrapper);
	if (keycode == ESC_CODE)
		full_quit(wrapper);
	return (0);
}

int	handle_keyrelease(int keycode, t_wrapper *wrapper)
{
	remove_key(&wrapper->keys, keycode);
	return (0);
}
