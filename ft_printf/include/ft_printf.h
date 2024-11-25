/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:21:51 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/25 11:45:05 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include "ft_color.h"
# include "ft_bool.h"
# include <stdarg.h>
# include <stdio.h>

# define SPECIFIERS "cspdiuxX%"
# define FLAGS "# +-0"

typedef struct s_option
{
	char	specifier;
	t_bool	sharp;
	t_bool	space;
	t_bool	plus;
	t_bool	minus;
	t_bool	zero;
	int		width;
	int		precision;
	int		length;
}	t_option;

typedef struct s_carac
{
	int		size;
	int		pad;
	int		padleft;
	int		zeros;
	char	sign_char;
	char	prefix[3];
	int		total_length;
	char	*content;
}	t_carac;

typedef enum e_length
{
	LONG_LONG = 4,
	LONG = 3,
	SHORT = 2,
	SHORT_SHORT = 1
}	t_length;

typedef struct s_size
{
	int	len;
	int	padded;
}	t_size;

void		ft_initoptions(struct s_option *options);
t_bool		ft_isspecifier(const char c);
t_bool		ft_isflag(const char c);
void		ft_addchar(int count, int zero);
void		ft_addchar(int count, int zero);
int			ft_getmax(int count, ...);
size_t		ft_parse_flags(const char **fmt, struct s_option *options);
size_t		ft_parse_width(const char **fmt, struct s_option *options);
size_t		ft_parse_precision(const char **fmt, struct s_option *options);
size_t		ft_parseoptions(const char *fmt, struct s_option *options);
void		ft_storeflag(const char c, struct s_option *options);
void		ft_storeint(const char c, int *n);
size_t		ft_storelength(const char *s, int *length);
t_bool		ft_getflag(int flag, char c);
int			ft_putcoptions_fd(const char c, struct s_option options, int fd);
int			ft_putdioptions_fd(int n, struct s_option options, int fd);
int			ft_putpoptions_fd(unsigned long long p, struct s_option options,
				int fd);
int			ft_putsoptions_fd(const char *s, struct s_option options, int fd);
int			ft_putuoptions_fd(unsigned int u, struct s_option options, int fd);
int			ft_putxoptions_fd(unsigned int x, struct s_option options, int fd);
size_t		ft_printwithoptions(int fd, struct s_option options, ...);
size_t		ft_handlespecifier(va_list ap, struct s_option *options, int fd);
int			ft_vdprintf(int fd, const char *fmt, va_list ap);
int			ft_printf(const char *fmt, ...);
int			ft_dprintf(int fd, const char *fmt, ...);
int			ft_vprintf(const char *fmt, va_list ap);
int			ft_debug(const char *fmt, ...);

#endif
