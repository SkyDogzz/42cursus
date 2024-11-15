/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:21:51 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/15 15:26:22 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

# define SPECIFIERS "cspdiuxX%"
# define FLAGS "# +"

# define LONG_LONG 4
# define LONG 3
# define SHORT 2
# define SHORT_SHORT 1

typedef struct s_option
{
	char	specifier;
	int		flag;
	int		width;
	int		precision;
	int		length;
}	t_option;

int	ft_printf(const char *fmt, ...);

#endif
