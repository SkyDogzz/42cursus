/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 23:38:07 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/16 23:40:58 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	execute_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = parse_args(cmd);
	if (!args || !args[0])
	{
		fprintf(stderr, "Command not found: %s\n", cmd);
		exit(EXIT_FAILURE);
	}
	if (ft_strchr(args[0], '/'))
		execve(args[0], args, envp);
	else
	{
		path = get_path(args[0], envp);
		if (!path)
		{
			fprintf(stderr, "Command not found: %s\n", args[0]);
			exit(EXIT_FAILURE);
		}
		execve(path, args, envp);
		free(path);
	}
	perror("execve");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	int		*pipes;
	int		nb_cmds;

	if (argc < 5)
	{
		fprintf(stderr, "Usage: %s infile cmd1 cmd2 [cmd3 ... cmdN] outfile\n",
			argv[0]);
		return (1);
	}
	nb_cmds = argc - 3;
	setup_pipes(&pipes, nb_cmds);
	spawn_processes(nb_cmds, argv, envp, pipes);
	free(pipes);
	wait_for_processes(nb_cmds);
	return (0);
}
