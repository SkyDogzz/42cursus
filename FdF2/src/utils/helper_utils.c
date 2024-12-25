/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:00:00 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/25 16:24:29 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	toggle_menu(t_wrapper *wrapper)
{
	if (wrapper->menu == 1)
		wrapper->menu = 0;
	else
		wrapper->menu = 1;
	display_map(wrapper);
}

void	toggle_helper(t_wrapper *wrapper)
{
	if (wrapper->map->helper == 1)
		wrapper->map->helper = 0;
	else
		wrapper->map->helper = 1;
	display_map(wrapper);
}

static void	display_menutop(t_wrapper *w, int *y)
{
	int		c;

	c = 0xFFFFFF;
	mlx_string_put(w->data.mlx_ptr, w->data.win_ptr, 20, *y += 15,
		c, "Keybinds :");
	mlx_string_put(w->data.mlx_ptr, w->data.win_ptr, 20, *y += 15,
		c, "(shift) x, y, z => rotate around axis");
	mlx_string_put(w->data.mlx_ptr, w->data.win_ptr, 20, *y += 15,
		c, "arrows => translate");
	mlx_string_put(w->data.mlx_ptr, w->data.win_ptr, 20, *y += 15,
		c, "page_up => zoom in");
	mlx_string_put(w->data.mlx_ptr, w->data.win_ptr, 20, *y += 15,
		c, "page_down => zoom out");
	mlx_string_put(w->data.mlx_ptr, w->data.win_ptr, 20, *y += 15,
		c, "j => increase height multiplier");
	mlx_string_put(w->data.mlx_ptr, w->data.win_ptr, 20, *y += 15,
		c, "k => decrease height multiplier");
	mlx_string_put(w->data.mlx_ptr, w->data.win_ptr, 20, *y += 15,
		c, "w => reset map");
}

static void	display_menu2(t_wrapper *w, int *y)
{
	int		c;
	char	*num;
	char	*str;

	c = 0xFFFFFF;
	mlx_string_put(w->data.mlx_ptr, w->data.win_ptr, 20, *y += 15,
		c, "space => toggle menu");
	mlx_string_put(w->data.mlx_ptr, w->data.win_ptr, 20, *y += 15,
		c, "c => bitwise color swap");
	mlx_string_put(w->data.mlx_ptr, w->data.win_ptr, 20, *y += 15,
		c, "r => randomize color");
	mlx_string_put(w->data.mlx_ptr, w->data.win_ptr, 20, *y += 15,
		c, "h => toggle helpers");
	mlx_string_put(w->data.mlx_ptr, w->data.win_ptr, 20, *y += 15,
		c, "esc => quit");
	num = ft_itoa((int)(w->map->zoom * 10));
	str = ft_strjoin("ZOOM = ", num);
	free(num);
	mlx_string_put(w->data.mlx_ptr, w->data.win_ptr, 20, *y += 15, c, str);
	free(str);
}

static void	display_menudown(t_wrapper *w, int *y)
{
	int		c;
	char	*num;
	char	*tmp;
	char	*tmp2;

	c = 0xFFFFFF;
	num = ft_itoa(w->offset_div);
	tmp = ft_strjoin("OFFSET DIV = ", num);
	free(num);
	mlx_string_put(w->data.mlx_ptr, w->data.win_ptr, 20, *y -= 15, c, tmp);
	free(tmp);
	num = ft_itoa(w->rotate_div);
	tmp = ft_strjoin("ROTATION = ", num);
	free(num);
	tmp2 = ft_strjoin(tmp, " / PI");
	free(tmp);
	mlx_string_put(w->data.mlx_ptr, w->data.win_ptr, 20, *y -= 15, c, tmp2);
	free(tmp2);
}

void	display_menu(t_wrapper *wrapper)
{
	int		y;

	y = 0;
	display_menutop(wrapper, &y);
	display_menu2(wrapper, &y);
	y = WINDOW_HEIGHT;
	display_menudown(wrapper, &y);
}

void	draw_helper(t_wrapper *wrapper)
{
	t_2vec		line[2];
	t_2color	clr;

	if (!wrapper->map->helper)
		return ;
	clr.start = HELPER_START;
	clr.end = HELPER_END;
	line[0].x = WINDOW_WIDTH / 2;
	line[0].y = 0;
	line[1].x = WINDOW_WIDTH / 2;
	line[1].y = WINDOW_HEIGHT;
	draw_line_zbuffer(line[0].x, line[0].y, 0,
		line[1].x, line[1].y, 0, clr, wrapper);
	line[0].x = 0;
	line[0].y = WINDOW_HEIGHT / 2;
	line[1].x = WINDOW_WIDTH;
	line[1].y = WINDOW_HEIGHT / 2;
	draw_line_zbuffer(line[0].x, line[0].y, 0,
		line[1].x, line[1].y, 0, clr, wrapper);
}
