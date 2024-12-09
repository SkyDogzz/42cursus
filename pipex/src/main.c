/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:17:42 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/09 20:20:32 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_cmd(t_cmd *cmds, int index)
{
	while (index)
	{
		free(cmds[--index].args[0]);
		free(cmds[index].args);
	}
	free(cmds);
	(void) index;
}

void	parse_args(t_pipex *pipex, int argc, char *argv[])
{
	int	pos;

	pipex->infile = ft_strdup(argv[1]);
	pipex->outfile = ft_strdup(argv[argc - 1]);
	pipex->cmds_num = argc - 3;
	pipex->cmds = (t_cmd *)malloc(sizeof(t_cmd) * pipex->cmds_num);
	if (!pipex->cmds)
		return ;
	pos = 0;
	while (pos < pipex->cmds_num)
	{
		pipex->cmds[pos].args = (char **)malloc(sizeof(char *) * (1 + 1));
		pipex->cmds[pos].args[0] = ft_strjoin("/bin/", ft_strdup(argv[pos + 2]));
		pipex->cmds[pos].args[1] = NULL;
		if (!pipex->cmds[pos].args[0])
			free_cmd(pipex->cmds, pos);
		pos++;
	}
	(void) pos;
}

void	free_full(t_pipex *pipex)
{
	free(pipex->infile);
	free(pipex->outfile);
	free_cmd(pipex->cmds, pipex->cmds_num);
}

void	print_pipex(t_pipex pipex)
{
	int	pos;
	ft_printf("infile = %s, outfile = %s\n", pipex.infile, pipex.outfile);

	pos = 0;
	while (pos < pipex.cmds_num)
	{
		ft_printf("cmd%d = %s ", pos, pipex.cmds[pos].args[0]);
		pos++;
	}
	ft_printf("\n");
}

#include <stdio.h>

int main(int argc, char *argv[], char *env[])
{
	t_pipex	pipex;    
	if (argc < 4)
	{
		ft_dprintf(2, "Usage %s infile cmd1 cmd2 ... cmdn outfile\n", argv[0]);
		exit(0);
	}
	parse_args(&pipex, argc, argv);
	if (access(pipex.infile, R_OK) != 0)
	{
		perror("Error");
		exit(0);
	}
	int in = open(pipex.infile, O_RDONLY);
	int out = open(pipex.outfile, O_WRONLY);
	print_pipex(pipex);
	dup2(in, 0);
	dup2(out, 1);
	execve(pipex.cmds->args[0], pipex.cmds->args, env);
	free_full(&pipex);
	(void) env;
}
