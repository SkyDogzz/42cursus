/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:21:51 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/20 18:57:03 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

# define SPECIFIERS "cspdiuxX%"
# define FLAGS "# +-0"

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

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
	int	size;
	int	pad;
	int	padleft;
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

// ft_printf
size_t	ft_printf(const char *fmt, ...);
size_t	ft_handlespecifier(va_list ap, struct s_option *options);
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
void	ft_storeflag(const char c, struct s_option *options);
void	ft_storeint(const char c, int *n);
size_t	ft_storelength(const char *s, int *length);
t_bool	ft_getflag(int flag, char c);

void	ft_initcaracs(struct s_carac *caracs);
int		ft_getmax(int count, ...);
int		ft_putcoptions_fd(const char c, struct s_option options, int fd);
int		ft_putsoptions_fd(const char *s, struct s_option options, int fd);
int		ft_putpoptions_fd(unsigned long long p, struct s_option options,
			int fd);
void	ft_addchar(int count, int zero);
void	ft_putstr_padded(const char *s, int count, int left);
int		ft_putdioptions_fd(int d, struct s_option options, int fd);
int		ft_putuoptions_fd(unsigned int u, struct s_option options, int fd);
int		ft_putxoptions_fd(unsigned int u, struct s_option options, int fd);

#endif
