/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:21:51 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/17 15:55:03 by skydogzz         ###   ########.fr       */
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

// ft_printf
int		ft_printf(const char *fmt, ...);
int		ft_printwithoptions(struct s_option options, ...);

// ft_parse
int		ft_parseoptions(const char *fmt, struct s_option *options);

// ft_option
void	ft_initoptions(struct s_option *options);
int		ft_isspecifier(const char c);
int		ft_isflag(const char c);
void	ft_storeflag(const char c, int *flag);
void	ft_storeint(const char c, int *n);
int		ft_storelength(const char *s, int *length);

// ft_char
int		ft_putcharoptions_fd(const char c, int fd);

// ft_p
void	ft_putp_fd(unsigned long long p, int fd, int big);
int		ft_countcharp(unsigned long long p);
int		ft_putpoptions_fd(unsigned long long p, int fd);

// ft_str
int		ft_putstroptions_fd(const char *s, int fd);

// ft_nbr
int		ft_countcharint(int n);
int		ft_putnbroptions_fd(int n, int fd);

// ft_u
int		ft_countcharu(unsigned int u);
int		ft_putuoptions_fd(unsigned int u, int fd);
void	ft_putu_fd(unsigned int u, int fd);

// ft_uint
int		ft_countcharx(unsigned int hex);
void	ft_putx_fd(unsigned int hex, int fd, int big);
int		ft_puthexbroptions_fd(unsigned int hex, int fd,
			struct s_option options);

#endif
