/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:00:27 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/28 19:55:28 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include <errno.h>
# include <string.h>
# include <X11/keysym.h>
# include "../.minilibx-linux/mlx.h"
# include <stdio.h>

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define MLX_ERROR 2
# define FOCAL 50

typedef enum s_key
{
	ESC = 65307
}	t_key;

typedef struct s_dim
{
	int	width;
	int	height;
}	t_dim;

typedef struct s_3vector
{
	float	x;
	float	y;
	float	z;
}	t_3vector;

typedef struct s_2vector
{
	int	x;
	int	y;
}	t_2vector;

typedef struct s_camera
{
	t_3vector	position;
	t_3vector	target;
	t_3vector	up;
}	t_camera;

typedef struct s_content
{
	t_dim		*dims;
	t_3vector	**map;
}	t_content;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

t_dim		*get_dim(const char *filename);
void		display_parsed(t_3vector **map, t_dim dims);
void		displaypos_parsed(t_3vector **map, t_dim dims);
int			handle_key(int key, t_mlx *mlx);
int			handle_no_event(void);
int			handle_mouse(int button, int x, int y, void *params);
int			full_quit(t_mlx *data);
void		free_map(t_3vector **map, int size);
t_3vector	**parse_map(const char *filename, t_dim dims);
void		projection(t_3vector p3d, t_2vector *p2d, float focal);

#endif
