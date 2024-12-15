/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:32:40 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/15 20:51:59 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	error_msg(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

static char *get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path_var;
    char	*full_path;
    int		i;

	for (i = 0; envp[i]; i++)
	{
	    if (ft_strncmp(envp[i], "PATH=", 5) == 0)
	    {
            path_var = envp[i] + 5;
            break;
        }
    }
    if (!envp[i])
        return NULL;
    paths = ft_split(path_var, ':');
    if (!paths)
        return NULL;

    i = 0;
    while (paths[i])
    {
        size_t path_len = ft_strlen(paths[i]);
        size_t cmd_len = ft_strlen(cmd);
        full_path = malloc(path_len + 1 + cmd_len + 1);
        if (!full_path)
            return NULL;
        ft_strlcpy(full_path, paths[i], path_len + 1);
        ft_strlcat(full_path, "/", path_len + 1 + 1 + cmd_len + 1);
        ft_strlcat(full_path, cmd, path_len + 1 + 1 + cmd_len + 1);
        if (access(full_path, X_OK) == 0)
        {
            int j = 0;
            while (paths[j])
                free(paths[j++]);
            free(paths);
            return full_path;
        }
        free(full_path);
        i++;
    }
    i = 0;
    while (paths[i])
        free(paths[i++]);
    free(paths);
    return NULL;
}

void execute_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;
	int		i;

	args = ft_split(cmd, ' ');
	if (!args || !args[0])
	{
		fprintf(stderr, "Command not found: %s\n", cmd);
		exit(EXIT_FAILURE);
	}
	if (ft_strchr(args[0], '/'))
	{
		if (execve(args[0], args, envp) == -1)
		{
			perror("execve");
			i = 0; while (args[i]) free(args[i++]); free(args);
			exit(EXIT_FAILURE);
		}
	}
	else
{
		path = get_path(args[0], envp);
		if (!path)
		{
			fprintf(stderr, "Command not found: %s\n", args[0]);
			i = 0; while (args[i]) free(args[i++]); free(args);
			exit(EXIT_FAILURE);
		}
		if (execve(path, args, envp) == -1)
		{
			perror("execve");
			free(path);
			i = 0; while (args[i]) free(args[i++]); free(args);
			exit(EXIT_FAILURE);
		}
		free(path);
	}
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

int main(int argc, char **argv, char **envp)
{
	int		fd_in;
	int		fd_out;
	int		i;
	int		nb_cmds;
	int		*pipes;
	pid_t	pid;
	int		status;

	if (argc < 5)
	{
		fprintf(stderr, "Usage: %s infile cmd1 cmd2 [cmd3 ... cmdN] outfile\n", argv[0]);
		return (1);
	}
	nb_cmds = argc - 3; 
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
		error_msg("open infile");
	fd_out = open(argv[argc-1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out < 0)
		error_msg("open outfile");
	pipes = malloc(sizeof(int) * 2 * (nb_cmds - 1));
	if (!pipes)
		error_msg("malloc pipes");
	for (i = 0; i < nb_cmds - 1; i++)
		if (pipe(pipes + i*2) == -1)
			error_msg("pipe");
	for (i = 0; i < nb_cmds; i++)
	{
		pid = fork();
		if (pid < 0)
			error_msg("fork");
		if (pid == 0)
		{
			if (i == 0)
				dup2(fd_in, STDIN_FILENO);
			else
				dup2(pipes[(i-1)*2], STDIN_FILENO);
			if (i == nb_cmds - 1)
				dup2(fd_out, STDOUT_FILENO);
			else
				dup2(pipes[i*2 + 1], STDOUT_FILENO);
			for (int j = 0; j < (nb_cmds-1)*2; j++)
				close(pipes[j]);
			close(fd_in);
			close(fd_out);
			execute_cmd(argv[2 + i], envp);
		}
	}
	for (int j = 0; j < (nb_cmds-1)*2; j++)
		close(pipes[j]);
	close(fd_in);
	close(fd_out);
	free(pipes);
	for (i = 0; i < nb_cmds; i++)
		wait(&status);
	return (0);
}
