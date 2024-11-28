/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:00:27 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/28 15:00:10 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include <errno.h>
# include <string.h>

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

t_dim	*get_dim(const char *filename);
void	display_parsed(t_vector **map, t_dim dims);

#endif
