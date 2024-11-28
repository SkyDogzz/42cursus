/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:06:57 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/28 15:14:51 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_fd_node
{
	int					fd;
	char				*store;
	struct s_fd_node	*next;
}	t_fd_node;

char		*get_next_line(int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
t_fd_node	*get_fd_node(t_fd_node **fd_list, int fd);
void		remove_fd_node(t_fd_node **fd_list, int fd);
void		full_close(int fd);

#endif
