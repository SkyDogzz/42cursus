/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:09:46 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/04 13:12:40 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include "keycode.h"
# include "../.minilibx/mlx.h"
# include <math.h>
# include <stdio.h>

# define WINDOW_WIDTH 1280.0
# define WINDOW_HEIGHT 720.0
# define HEIGHT_DIV 1.0
# define HEIGHT_MODIFIER 0.8
# define ZOOM 0.25
# define ZOOM_MODIFIER 0.8
# define SEED 123456
# define ROTATE_DIV 32
# define OFFSET_DIV 20
# define HELPER TRUE

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

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
	int	helper;
}	t_map;

typedef struct s_wrapper
{
	t_map	*map;
	t_mlx	data;
	t_bool	menu;
}	t_wrapper;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

t_map			*parse_map(const char *filename);
void			print_map(t_map *map);
int				full_quit(t_mlx *data);
void			exit_msg_code(const char *message, int code);
int				handle_key(int keycode, t_wrapper *wrapper);
int				handle_no_event(t_wrapper *wrapper);
int				handle_mouse(void);
int				get_color(const char *s);
int				atoi_base(const char *s, const char *base, const char *base2);
int				get_width(const char *line);
void			draw_line(t_2vec start, t_2vec end, t_2color color,
					t_wrapper wrapper);
void			display_map(t_wrapper *wrapper);
void			rotatex_map(t_map *map, float angle);
void			rotatey_map(t_map *map, float angle);
void			rotatez_map(t_map *map, float angle);
void			fill_map(t_map *map, int fd);
void			rotate(t_wrapper *wrapper, int keycode);
void			change_all_color(t_wrapper *wrapper);
unsigned int	pseudo_random(unsigned int seed);
void			randomize_color(t_wrapper *wrapper);
void			refill_map(t_wrapper *wrapper);
void			change_height(t_wrapper *wrapper, int keycode);
void			base_rotate(t_wrapper *wrapper);
void			translate_camera(t_wrapper *wrapper, int keycode);

#endif
