/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:18:29 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/16 23:40:24 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_parser
{
	int		in_single_quote;
	int		in_double_quote;
	char	**args;
	int		arg_count;
	char	*current_arg;
	size_t	arg_len;
	char	c;
}	t_parser;

typedef struct s_child_data
{
	int	i;
	int	fd_in;
	int	fd_out;
	int	*pipes;
	int	nb_cmds;
}	t_child_data;

void	error_msg(const char *msg);
char	*get_path(char *cmd, char **envp);
void	free_paths(char **paths);
char	*construct_full_path(char *path, char *cmd);
void	close_pipes(int *pipes, int size);
void	handle_child_process(t_child_data data);
void	execute_cmd(char *cmd, char **envp);
char	**parse_args(const char *cmd_line);
void	setup_pipes(int **pipes, int nb_cmds);
void	wait_for_processes(int nb_cmds);
void	spawn_processes(int nb_cmds, char **argv, char **envp, int *pipes);

#endif
