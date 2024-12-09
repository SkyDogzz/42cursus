/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:29:56 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/08 22:14:58 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	display_menutop(t_wrapper *wrapper)
{
	int		y;
	int		c;
	void	*m;
	void	*w;

	y = 5;
	m = wrapper->data.mlx_ptr;
	w = wrapper->data.win_ptr;
	c = 0xFFFFFF;
	mlx_string_put(m, w, 20, y += 15, c, "Keybinds :");
	mlx_string_put(m, w, 20, y += 15, c, "(shift) x to rotate around x axis");
	mlx_string_put(m, w, 20, y += 15, c, "(shift) y to rotate around y axis");
	mlx_string_put(m, w, 20, y += 15, c, "(shift) z to rotate around z axis");
	mlx_string_put(m, w, 20, y += 15, c, "arrows to translate");
	mlx_string_put(m, w, 20, y += 15, c, "page_up to zoom in");
	mlx_string_put(m, w, 20, y += 15, c, "page_down to zoom out");
	mlx_string_put(m, w, 20, y += 15, c, "j to increase height multiplier");
	mlx_string_put(m, w, 20, y += 15, c, "k to decrease height multiplier");
	mlx_string_put(m, w, 20, y += 15, c, "w to reset map");
	mlx_string_put(m, w, 20, y += 15, c, "space to toggle menu");
	mlx_string_put(m, w, 20, y += 15, c, "c to bitwise color");
	mlx_string_put(m, w, 20, y += 15, c, "r to randomise (seeded) color");
	mlx_string_put(m, w, 20, y += 15, c, "h to toggle helpers");
	mlx_string_put(m, w, 20, y += 15, c, "esc to quit");
}

char *get_2decimal(float nbr)
{
	char	*dec;

	dec = (char *)malloc(sizeof(char) * 4);
	dec[0] = '.';
	dec[1] = ((int)(nbr * 100) % 10) + '0';
	dec[2] = ((int)(nbr * 10) % 10) + '0';
	dec[3] = 0;
	return (dec);
}

void	display_menudown2(t_wrapper *w, int y)
{
	int		c;
	char	*num;
	char	*joined;
	char	*joined2;

	c = 0xFFFFFF;
	num = ft_itoa((int)w->map->zoom);
	joined = ft_strjoin("ZOOM = ", num);
	free(num);
	num = get_2decimal(w->map->zoom);
	joined2 = ft_strjoin(joined, num);
	free(joined);
	free(num);
	mlx_string_put(w->data.mlx_ptr, w->data.win_ptr, 20, y -= 15, c, joined2);
	free(joined2);
}

void	display_menudown(t_wrapper *w, int y)
{
	int		c;
	char	*num;
	char	*joined;
	char	*joined2;

	c = 0xFFFFFF;
	num = ft_itoa(w->offset_div);
	joined = ft_strjoin("(shift - ctrl / ',' - '.') OFFSET DIV ", num);
	free(num);
	mlx_string_put(w->data.mlx_ptr, w->data.win_ptr, 20, y -= 15, c, joined);	
	free(joined);
	num = ft_itoa(w->rotate_div);
	joined = ft_strjoin("(shift - ctrl / '[' - ']') ROTATION ", num);
	free(num);
	joined2 = ft_strjoin(joined, " / PI");
	free(joined);
	mlx_string_put(w->data.mlx_ptr, w->data.win_ptr, 20, y -= 15, c, joined2);
	free(joined2);
	display_menudown2(w, y);

}

void	display_menu(t_wrapper *wrapper)
{
	display_menutop(wrapper);
	display_menudown(wrapper, WINDOW_HEIGHT);
}

void	toggle_menu(t_wrapper *wrapper)
{
	if (wrapper->menu == TRUE)
		wrapper->menu = FALSE;
	else
		wrapper->menu = TRUE;
	display_map(wrapper);
}

void	toggle_helper(t_wrapper *wrapper)
{
	if (wrapper->map->helper == TRUE)
		wrapper->map->helper = FALSE;
	else
		wrapper->map->helper = TRUE;
	display_map(wrapper);
}

int	handle_no_event(t_wrapper *wrapper)
{
	return (0);
	(void) wrapper;
}

void	draw_helper(t_wrapper *wrapper)
{
	t_2vec		line[2];
	t_2color	color;

	if (!wrapper->map->helper)
		return ;
	color.start = HELPER_START;
	color.end = HELPER_END;
	line[0].x = WINDOW_WIDTH / 2;
	line[0].y = 0;
	line[1].x = WINDOW_WIDTH / 2;
	line[1].y = WINDOW_HEIGHT;
	draw_line(line[0], line[1], color, *wrapper);
	line[0].x = 0;
	line[0].y = WINDOW_HEIGHT / 2;
	line[1].x = WINDOW_WIDTH;
	line[1].y = WINDOW_HEIGHT / 2;
	draw_line(line[0], line[1], color, *wrapper);
}
