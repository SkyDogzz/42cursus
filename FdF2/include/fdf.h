/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:09:46 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/02 02:36:15 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include "keycode.h"
# include <mlx.h>

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
	float	height;
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

t_map	*parse_map(const char *filename);
void	print_map(t_map *map);
int		full_quit(t_mlx *data);
void	exit_msg_code(const char *message, int code);
int		handle_key(int keycode, t_mlx *data);
int		handle_no_event(void);
int		handle_mouse(void);
int		get_color(const char *s);
int		atoi_base(const char *s, const char *base, const char *base2);
int		get_width(const char *line);
void	display_map(t_mlx data, t_map map);

#endif
