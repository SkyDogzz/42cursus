/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:39:03 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/25 11:44:52 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_setcolor(int r, int g, int b, t_bool is_background)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		ft_dprintf(2, "Invalid RGB values: (%d, %d, %d).\n", r, g, b);
		return ;
	}
	if (is_background)
		ft_printf("%s48;2;%d;%d;%dm", ANSI_COLOR_ESCAPE, r, g, b);
	else
		ft_printf("%s38;2;%d;%d;%dm", ANSI_COLOR_ESCAPE, r, g, b);
}

void	ft_resetcolor(void)
{
	ft_printf("%s0m", ANSI_COLOR_ESCAPE);
}
