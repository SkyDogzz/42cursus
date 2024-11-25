/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:53:04 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/25 11:44:03 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLOR_H
# define FT_COLOR_H

# include "ft_bool.h"

# define COLOR_RESET	"\x1B[0m"
# define COLOR_RED		"\x1B[31m"
# define COLOR_GREEN	"\x1B[32m"
# define COLOR_YELLOW	"\x1B[33m"
# define COLOR_BLUE		"\x1B[34m"
# define COLOR_MAGENTA	"\x1B[35m"
# define COLOR_CYAN		"\x1B[36m"
# define COLOR_WHITE	"\x1B[37m"

# define ANSI_COLOR_ESCAPE "\x1B["

void	ft_setcolor(int r, int g, int b, t_bool is_background);
void	ft_resetcolor(void);

#endif
