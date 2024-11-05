/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:07:50 by marvin            #+#    #+#             */
/*   Updated: 2024/11/05 15:51:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>

/*
--------------------------------------------------------------------------------
LIBC FONCTIONS
--------------------------------------------------------------------------------
*/

// char fonctions
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_toupper(int c);
int	ft_tolower(int c);

// str fonctions
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t ft_strlcpy(char *d, const char *s, size_t n);
size_t ft_strlcat(char *d, const char *s, size_t n);
char	*strnstr(const char *big, const char *little, size_t len);
int	ft_atoi(const char *s);

// mem fonctions

#endif
