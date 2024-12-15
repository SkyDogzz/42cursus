/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:18:29 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/15 20:48:31 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

void	error_msg(const char *msg);
void	execute_cmd(char *cmd, char **envp);
void	close_pipes(int *pipes, int n);
int		*init_pipes(int nb_cmds);
void	wait_for_children(int nb_cmds);
void	free_str_array(char **array);

#endif
