/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:09:46 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/03 13:13:37 by tstephan         ###   ########.fr       */
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

# define WINDOW_WIDTH 1280.0
# define WINDOW_HEIGHT 720.0
# define PI 3.1415

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
}	t_map;

typedef struct s_wrapper
{
	t_map	*map;
	t_mlx	data;
}	t_wrapper;

t_map	*parse_map(const char *filename);
void	print_map(t_map *map);
int		full_quit(t_mlx *data);
void	exit_msg_code(const char *message, int code);
int		handle_key(int keycode, t_wrapper *wrapper);
int		handle_no_event(t_wrapper *wrapper);
int		handle_mouse(void);
int		get_color(const char *s);
int		atoi_base(const char *s, const char *base, const char *base2);
int		get_width(const char *line);
void	display_map(t_mlx data, t_map map);

#endif
