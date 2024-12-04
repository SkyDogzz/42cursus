/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:44:02 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/04 20:37:59 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	on_keydown(int keycode, void *wrapper)
{
	ft_printf("keydown %d\n", keycode);
	return (0);
	(void) wrapper;
}

void	set_hook(t_wrapper *wrapper)
{
	mlx_loop_hook(wrapper->data.mlx_ptr, &handle_no_event, wrapper);
	mlx_hook(wrapper->data.win_ptr, 17, 0, &full_quit, wrapper);
	mlx_hook(wrapper->data.win_ptr, KeyPress, KeyPressMask, &handle_key,
		wrapper);
	mlx_do_key_autorepeaton(wrapper->data.mlx_ptr);
}

int	main(int argc, char *argv[])
{
	t_wrapper	wrapper;

	if (argc <= 1)
	{
		ft_dprintf(2, "Usage: %s <input_file>\n", argv[0]);
		exit(0);
	}
	wrapper.menu = MENU;
	wrapper.map = parse_map(argv[1]);
	wrapper.map->filename = argv[1];
	setup_map(&wrapper);
	wrapper.data.mlx_ptr = mlx_init();
	wrapper.data.win_ptr = mlx_new_window(wrapper.data.mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, "FdF Goes Brrr!!!");
	set_hook(&wrapper);
	base_rotate(&wrapper);
	display_map(&wrapper);
	mlx_loop(wrapper.data.mlx_ptr);
	mlx_destroy_display(wrapper.data.mlx_ptr);
	free(wrapper.data.mlx_ptr);
	free_map_full(wrapper.map);
	return (EXIT_SUCCESS);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}
