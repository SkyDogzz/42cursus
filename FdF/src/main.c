/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:53:31 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/29 19:22:35 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	setup_mlx(t_mlx data)
{
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"FdF goes brrrr!");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_key_hook(data.win_ptr, &handle_key, &data);
	mlx_mouse_hook(data.win_ptr, &handle_mouse, &data);
	mlx_hook(data.win_ptr, 17, 0, &full_quit, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}

void	init_render(t_render *render)
{
	render->camera.pos.x = CAMERA_POS_X;
	render->camera.pos.y = CAMERA_POS_Y;
	render->camera.pos.z = CAMERA_POS_Z;
	render->scene.center.x = SCENE_POS_X;
	render->scene.center.y = SCENE_POS_Y;
	render->scene.center.z = SCENE_POS_Z;
}

int	main(int argc, char *argv[])
{
	t_content	content;
	t_mlx		*data;
	// t_render	render;

	if (argc < 2)
	{
		ft_dprintf(2, "Usage: %s <input_file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	data = (t_mlx *)malloc(sizeof(t_mlx) * 1);
	if (!data)
		return (EXIT_FAILURE);
	setup_mlx(*data);
	content.dims = get_dim(argv[1]);
	content.map = parse_map(argv[1], *content.dims);
	free_map(content.map, content.dims->height);
	free(content.dims);
	free(data);
	return (EXIT_SUCCESS);
}
