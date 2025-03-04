/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:07:50 by marvin            #+#    #+#             */
/*   Updated: 2024/12/17 20:27:54 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "ft_bool.h"

/*
--------------------------------------------------------------------------------
LIBC FONCTIONS
--------------------------------------------------------------------------------
*/

// char fonctions
int		ft_isalpha(int c);
int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
// all functions under => to test
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_isblank(int c);
int		ft_isspace(int c);
char	*ft_swapcase(const char *s);
int		ft_abs(int n);
char	*ft_strrev(const char *s);
char	*ft_strpad(const char *s, char pad, size_t len, int left);
int		ft_atoi_base(const char *s, const char *base);
int		ft_gettotal(const int *tab, size_t len);
int		ft_countwords(const char *s, char c);

// str fonctions
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *d, const char *s, size_t n);
size_t	ft_strlcat(char *d, const char *s, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *s);

// mem fonctions
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_bzero(void *s, size_t n);

// using malloc
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);

/*
--------------------------------------------------------------------------------
MORE FONCTIONS
--------------------------------------------------------------------------------
*/

char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	**ft_split(const char *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*
--------------------------------------------------------------------------------
BONUS
--------------------------------------------------------------------------------
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *newl);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstadd_back(t_list **lst, t_list *newl);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
