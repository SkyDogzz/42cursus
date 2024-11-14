/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:36:11 by marvin            #+#    #+#             */
/*   Updated: 2024/11/14 17:46:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "libft_bonus.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include <stdio.h>

# define FLAGS "-+ 0#"
# define SPECIFIERS "cspdiuxX%"

typedef enum a_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef enum a_len
{
	SHORT_SHORT = 1,
	SHORT = 2,
	LONG = 3,
	LONG_LONG = 4
}	t_len;

typedef struct s_option
{
	char	specifier;
	int		flag;
	int		width;
	int		precision;
	int		length;	
}	t_option;

typedef struct s_width
{
	int			n;
	int			width;
	char		c;
	enum a_bool	be;
	int			fd;
}	t_width;

// ft_option.c
int			ft_isflag(char c);
int			ft_isspecifier(char c);
void		ft_store_int(int *len, char c);
void		ft_store_flag(int *flag, char c);
enum a_bool	ft_getflag(int flag, char c);

// ft_ptr.c
void		ft_putptr_fd(void *p, int fd);
int			ft_putptr_fd_options(void *p, int fd, struct s_option options);

// ft_int.c
int			ft_putnbr_fd_options(int i, int fd, struct s_option options);
int			ft_putunbr_fd_options(unsigned int i, int fd,
				struct s_option options);
void		ft_putunbr_fd(unsigned int n, int fd);
int			ft_countcharint(int n);
void		ft_putnbr_width(struct s_width width);

// ft_char
void		ft_addchar(int n, char c, int fd);
int			ft_putchar_fd_options(char c, int fd, struct s_option options);

// ft_str
int			ft_putstr_fd_options(char *s, int fd, struct s_option options);

// ft_hex
void		ft_puthex_fd(unsigned int n, char spe, int fd);
int			ft_puthex_fd_options(unsigned int n, int fd, struct s_option options);

// ft_parse
char		*ft_parse_first(struct s_option *options, char *s);
char		*ft_parse_second(struct s_option *options, char *s);

// ft_printf
int			ft_print_with_option(struct s_option options, ...);
int			ft_printf(const char *s, ...);

#endif
