/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:21:51 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/17 17:20:55 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

# include <stdio.h>

# define SPECIFIERS "cspdiuxX%"
# define FLAGS "-# +"

typedef struct s_option
{
	char	specifier;
	int		flag;
	int		width;
	int		precision;
	int		length;
}	t_option;

typedef enum e_length
{
	LONG_LONG = 4,
	LONG = 3,
	SHORT = 2,
	SHORT_SHORT = 1
}	t_length;

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

// ft_printf
size_t	ft_printf(const char *fmt, ...);
size_t	ft_handlespecifier(const char **fmt, va_list ap,
			struct s_option *options);
size_t	ft_printwithoptions(t_option options, ...);

// ft_parse
size_t	ft_parse_flags(const char **fmt, t_option *options);
size_t	ft_parse_width(const char **fmt, struct s_option *options);
size_t	ft_parse_precision(const char **fmt, struct s_option *options);
size_t	ft_parseoptions(const char *fmt, struct s_option *options);

// ft_option
void	ft_initoptions(struct s_option *options);
t_bool	ft_isspecifier(const char c);
t_bool	ft_isflag(const char c);

// ft_store
void	ft_storeflag(const char c, int *flag);
void	ft_storeint(const char c, int *n);
size_t	ft_storelength(const char *s, int *length);
enum e_bool	ft_getflag(int flag, char c);

// ft_char
size_t	ft_putcharoptions_fd(const char c, int fd, struct s_option option);
void	ft_addchar(const char c, int fd, int count);

// ft_p
size_t	ft_putpoptions_fd(unsigned long long p, int fd);
size_t	ft_countcharp(unsigned long long p);
void	ft_putp_fd(unsigned long long p, int fd, int big);

// ft_str
size_t	ft_putstroptions_fd(const char *s, int fd);

// ft_nbr
size_t	ft_putnbroptions_fd(int n, int fd);
size_t	ft_countcharint(int n);

// ft_u
size_t	ft_putuoptions_fd(unsigned int u, int fd);
size_t	ft_countcharu(unsigned int u);
void	ft_putu_fd(unsigned int u, int fd);

// ft_uint
size_t	ft_puthexbroptions_fd(unsigned int hex, int fd,
			struct s_option options);
size_t	ft_countcharx(unsigned int hex);
void	ft_putx_fd(unsigned int hex, int fd, int big);

#endif
