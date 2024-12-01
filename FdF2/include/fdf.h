/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:09:46 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/30 17:21:20 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include <mlx.h>

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

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
void	exit_msg_code(const char *message, int code);

#endif
