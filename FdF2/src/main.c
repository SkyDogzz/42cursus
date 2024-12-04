/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:44:02 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/04 17:38:25 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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
	mlx_loop_hook(wrapper.data.mlx_ptr, &handle_no_event, &wrapper);
	mlx_key_hook(wrapper.data.win_ptr, &handle_key, &wrapper);
	mlx_hook(wrapper.data.win_ptr, 17, 0, &full_quit, &wrapper.data);
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

// int main(void)
// {
// 	// t_mlx	data;
// 	// data.mlx_ptr = mlx_init();
// 	// data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH,
// 		// WINDOW_HEIGHT, "FdF Goes Brrr!!!");
// 	// data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH,
// 	WINDOW_HEIGHT);
// 	// data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
// 	&data.img.line_len, &data.img.endian);
// 	img_pix_put(&data.img, 100, 100, 0xFFFFFF);
// 	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, 0, 0);
// 	mlx_loop(data.mlx_ptr);
// 	return (0);
// }
