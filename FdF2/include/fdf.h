/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:09:46 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/26 10:46:16 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <float.h>
# include <X11/X.h>
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include "../.minilibx/mlx.h"

/*
**  WINDOW / PARAMS
*/
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define HEIGHT_DIV 1.0f
# define HEIGHT_MODIFIER 0.8f
# define ZOOM 0.25f
# define ZOOM_MODIFIER 0.95f
# define SEED 123456
# define ROTATE_DIV 320
# define OFFSET_DIV 200
# define HELPER 0
# define HELPER_START 0xFF00FF
# define HELPER_END 0x00FF00
# define MENU 1

/*
**  KEYCODES
*/
# define SPACE_CODE 32
# define COMMA_CODE 44
# define DOT_CODE 46
# define BRACE_O_CODE 91
# define BRACE_C_CODE 93
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

/*
**  STRUCTS
*/
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
	t_cont	*content;
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
	int		menu;
	t_list	*keys;
	int		offset_div;
	int		rotate_div;
	float	*z_buffer;
}	t_wrapper;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_line_params
{
	t_2vec	p0;
	t_2vec	p1;
	t_2vec	d;
	t_2vec	step;
	t_2vec	err;
	float	steps;
	float	dz;
	float	current_z;
	float	t;
	t_color	start;
	t_color	end;
}	t_line_params;

typedef struct s_lineinfo
{
	t_3vec		start;
	t_3vec		end;
	t_2color	color;
}	t_lineinfo;

/*
**  Function Prototypes
*/

/* main.c */
int		main(int argc, char **argv);

/* setup.c */
void	setup(t_wrapper *wrapper);
void	setup_map(t_wrapper *wrapper);

/* event_exit.c */
int		full_quit(t_wrapper *wrapper);
void	exit_msg_code(const char *message, int code);

/* event_key.c */
int		handle_keypress(int keycode, t_wrapper *wrapper);
int		handle_keyrelease(int keycode, t_wrapper *wrapper);

/* event_handlers.c */
int		handle_no_event(t_wrapper *wrapper);
int		handle_rotation(t_wrapper *wrapper);
int		handle_translation(t_wrapper *wrapper);
int		handle_misc(t_wrapper *wrapper);

/* key_utils.c */
void	add_key(t_list **keys, int keycode);
void	remove_key(t_list **keys, int keycode);
t_bool	inlist(t_list *keys, int keycode);
void	free_keys(t_list **keys);

/* map_parse.c */
t_map	*parse_map(const char *filename);
void	fill_map(t_map *map, int fd);
int		get_width(const char *line);
int		get_height(int fd);

/* map_refill.c */
void	refill_map(t_wrapper *wrapper);

/* map_utils.c */
t_map	*init_map(t_map *map);
void	free_map_full(t_map *map);
void	process_line(t_map *map, char *line, int y, t_dim dims);
void	fill_point(t_map *map, t_2vec p, char **next, t_dim dims);

/* rotation_utils.c */
void	rotate(t_wrapper *wrapper);
void	base_rotate(t_wrapper *wrapper);

/* rotation_ops.c */
void	rotatex_map(t_map *map, float angle);
void	rotatey_map(t_map *map, float angle);
void	rotatez_map(t_map *map, float angle);

/* color_utils.c */
void	change_all_color(t_wrapper *wrapper);
void	randomize_color(t_wrapper *wrapper);
int		pseudo_random(int seed);
int		colormid(t_2color color, int total, int act);
int		get_color2(t_2color color, double line_length, int pos);

/* zoom_utils.c */
void	change_zoom(t_wrapper *wrapper);
void	translate_camera(t_wrapper *wrapper);
void	change_height(t_wrapper *wrapper);
void	reset_map(t_wrapper *wrapper);

/* helper_utils.c */
void	toggle_menu(t_wrapper *wrapper);
void	display_menu(t_wrapper *wrapper);
void	toggle_helper(t_wrapper *wrapper);
void	draw_helper(t_wrapper *wrapper);

/* math_utils.c */
t_2vec	get_step(t_2vec start, t_2vec end);
float	ft_min_float(float f1, float f2);
int		get_color(const char *s);
void	update_position(t_2vec *start, const t_2vec *s, t_2vec *e,
			const t_2vec *d);
int		atoi_base(const char *s, const char *b1, const char *b2);

/* draw_map.c */
void	display_map(t_wrapper *wrapper);
void	display_map_loop(t_wrapper *wrap, t_2vec *pos);
void	clear_zbuffer(float *zbuffer, int width, int height);

/* draw_line.c */
void	draw_line_zbuffer(const t_lineinfo *info, t_wrapper *wrapper);
void	init_line_params(t_line_params *p, t_3vec s, t_3vec e);
void	compute_color(t_line_params *p, t_2color color);
void	draw_pixel(t_line_params *p, t_wrapper *w);
void	img_pix_put(const t_img *img, int x, int y, int color);

/* draw_helpers.c */
void	draw_vertical_lines(t_wrapper *wrapper, int x, int y, t_2vec start2d);
void	draw_horizontal_lines(t_wrapper *wrapper, int x, int y, t_2vec start2d);
int		img_pix_get(const t_img *img, int x, int y);

/* You might add more prototypes as needed */

#endif
