/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:09:46 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/08 17:06:13 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include "../.minilibx/mlx.h"
# include <math.h>
# include <X11/X.h>

# define WINDOW_WIDTH 1280.0
# define WINDOW_HEIGHT 720.0
# define HEIGHT_DIV 1.0
# define HEIGHT_MODIFIER 0.8
# define ZOOM 0.25
# define ZOOM_MODIFIER 0.8
# define SEED 123456
# define ROTATE_DIV 32
# define OFFSET_DIV 20
# define HELPER FALSE
# define HELPER_START 0xFF00FF
# define HELPER_END 0x00FF00
# define MENU TRUE

# define SPACE_CODE 32
# define C_CODE 99
# define H_CODE 104
# define J_CODE 106
# define K_CODE 107
# define R_CODE 114
# define W_CODE 119
# define X_CODE 120
# define Y_CODE 121
# define Z_CODE 122
# define ESC_CODE 65307
# define LEFT_ARROW_CODE 65361
# define UP_ARROW_CODE 65362
# define RIGHT_ARROW_CODE 65363
# define DOWN_ARROW_CODE 65364
# define PAGEUP 65365
# define PAGEDOWN 65366
# define SHIFT_CODE 65505
# define CTRL_CODE 65507

typedef struct s_2vec
{
	int	x;
	int	y;
}	t_2vec;

typedef struct s_2color
{
	int	start;
	int	end;
}	t_2color;

typedef struct s_3vec
{
	float	x;
	float	y;
	float	z;
}	t_3vec;

typedef struct s_cont
{
	t_3vec	pos;
	int		color;
}	t_cont;

typedef struct s_dim
{
	int	width;
	int	height;
}	t_dim;

typedef struct s_map
{
	t_cont	**content;
	t_dim	dims;
	float	zoom;
	float	height_div;
	char	*filename;
	t_2vec	offset;
	int		helper;
}	t_map;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_mlx;

typedef struct s_wrapper
{
	t_map	*map;
	t_mlx	data;
	t_bool	menu;
	t_list	*keys;
}	t_wrapper;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

// color_utils.c
void	change_all_color(t_wrapper *wrapper);
int		pseudo_random(int seed);
void	randomize_color(t_wrapper *wrapper);
int		colormid(t_2color color, int total, int act);
int		get_color2(t_2color color, double line_length, int pos);

// zoom_utils.c
void	change_zoom(t_wrapper *wrapper, int keycode);
void	translate_camera(t_wrapper *wrapper);
void	change_height(t_wrapper *wrapper, int keycode);
void	reset_map(t_wrapper *wrapper);

// map_utils.x
t_map	*init_map(t_map *map);
void	free_map_full(t_map *map);
void	free_map_content(t_map *map, int pos);
void	refill_map(t_wrapper *wrapper);
void	setup_map(t_wrapper *wrapper);

// map_parsing.c
t_map	*parse_map(const char *filename);
void	fill_map(t_map *map, int fd);
void	process_line(t_map *map, char *line, int y, t_dim dims);
void	fill_point(t_map *map, t_2vec pos, char **next, t_dim dims);
int		get_width(const char *line);

// rotation_utils.c
void	rotatex_map(t_map *map, float angle);
void	rotatey_map(t_map *map, float angle);
void	rotatez_map(t_map *map, float angle);
void	rotate(t_wrapper *wrapper);
void	base_rotate(t_wrapper *wrapper);

// draw_utils.c
void	draw_line(t_2vec start, t_2vec end, t_2color color, t_wrapper wrapper);
void	draw_vertical_lines(t_wrapper *wrapper, int x, int y, t_2vec start);
void	draw_horizontal_lines(t_wrapper *wrapper, int x, int y, t_2vec start);
void	display_map(t_wrapper *wrapper);
void	display_map_loop(t_wrapper *wrap, t_2vec *pos);

// helper_utils.c
void	toggle_menu(t_wrapper *wrapper);
void	display_menu(t_wrapper *wrapper);
void	toggle_helper(t_wrapper *wrapper);
void	draw_helper(t_wrapper *wrapper);
int		handle_no_event(t_wrapper *wrapper);

// event_handling.c
int		handle_key(int keycode, t_wrapper *wrapper);
int		handle_mouse(void);
void	exit_msg_code(const char *message, int code);
int		full_quit(t_wrapper *wrapper);
int		atoi_base(const char *s, const char *base, const char *base2);

// math_utils.c
t_2vec	get_step(t_2vec start, t_2vec end);
float	min(float f1, float f2);
int		get_color(const char *s);
void	update_position(t_2vec *start, t_2vec *s, t_2vec *e, t_2vec *d);
int		get_height(int fd);

// main.c
int		main(int argc, char *argv[]);
void	print_map(t_map *map);
void	img_pix_put(t_img *img, int x, int y, int color);
int		handle_keypress(int keycode, t_wrapper *wrapper);
int		handle_keyrelease(int keycode, t_wrapper *wrapper);
void	add_key(t_list **keys, int keycode);
void	remove_key(t_list **keys, int keycode);
t_bool	inlist(t_list *keys, int keycode);
void	free_keys(t_list **keys);

#endif
