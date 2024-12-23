/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 23:13:50 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/23 16:27:33 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	close_pipes(int *pipes, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		close(pipes[i]);
		i++;
	}
}

void	handle_child_process(t_child_data data)
{
	if (data.i == 0)
		dup2(data.fd_in, STDIN_FILENO);
	else
		dup2(data.pipes[(data.i - 1) * 2], STDIN_FILENO);
	if (data.i == data.nb_cmds - 1)
		dup2(data.fd_out, STDOUT_FILENO);
	else
		dup2(data.pipes[data.i * 2 + 1], STDOUT_FILENO);
	close_pipes(data.pipes, 2 * (data.nb_cmds - 1));
	close(data.fd_in);
	close(data.fd_out);
}

void	setup_pipes(int **pipes, int nb_cmds)
{
	int	i;

	*pipes = (int *)malloc(sizeof(int) * 2 * (nb_cmds - 1));
	if (!*pipes)
		error_msg("malloc pipes");
	i = 0;
	while (i < nb_cmds - 1)
	{
		if (pipe(*pipes + i * 2) == -1)
			error_msg("pipe");
		i++;
	}
}

void	wait_for_processes(int nb_cmds)
{
	int	i;
	int	status;
	int	exit_code;

	exit_code = 0;
	i = 0;
	while (i < nb_cmds)
	{
		if (wait(&status) == -1)
		{
			perror("wait");
			exit(EXIT_FAILURE);
		}
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			exit_code = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
		{
			ft_dprintf(2, "Process terminated by signal: %d\n",
				WTERMSIG(status));
			exit_code = 128 + WTERMSIG(status);
		}
		i++;
	}
	exit(exit_code);
}

void	spawn_processes(int nb_cmds, char **argv, char **envp, int *pipes)
{
	pid_t			pid;
	t_child_data	data;

	data.nb_cmds = nb_cmds;
	data.fd_in = open(argv[1], O_RDONLY);
	data.fd_out = open(argv[data.nb_cmds + 2], O_WRONLY | O_CREAT | O_TRUNC,
			0644);
	data.pipes = pipes;
	data.i = 0;
	while (data.i < data.nb_cmds)
	{
		pid = fork();
		if (pid == 0)
		{
			handle_child_process(data);
			execute_cmd(argv[2 + data.i], envp);
		}
		data.i++;
	}
	close_pipes(data.pipes, 2 * (data.nb_cmds - 1));
	close(data.fd_in);
	close(data.fd_out);
}
