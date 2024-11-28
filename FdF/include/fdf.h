/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:00:27 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/28 18:13:21 by tstephan         ###   ########.fr       */
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

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define MLX_ERROR 2

typedef enum s_key
{
	ESC = 65307
}	t_key;

typedef struct s_dim
{
	int	width;
	int	height;
}	t_dim;

typedef struct s_vector
{
	int	x;
	int	y;
	int	z;
}	t_vector;

typedef struct s_content
{
	t_dim		*dims;
	t_vector	**map;
}	t_content;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

t_dim		*get_dim(const char *filename);
void		display_parsed(t_vector **map, t_dim dims);
void		displaypos_parsed(t_vector **map, t_dim dims);
int			handle_key(int key, t_mlx *mlx);
int			handle_no_event(void);
int			handle_mouse(int button, int x, int y, void *params);
int			full_quit(t_mlx *data);
void		free_map(t_vector **map, int size);
t_vector	**parse_map(const char *filename, t_dim dims);

#endif
