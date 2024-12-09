/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:17:42 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/09 19:06:05 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_tab(char **cmds, int index)
{
	while (index)
		free(cmds[--index]);
	free(cmds);
}

void	parse_args(t_pipex *pipex, int argc, char *argv[])
{
	int	pos;

	pipex->infile = ft_strdup(argv[1]);
	pipex->outfile = ft_strdup(argv[argc - 1]);
	pipex->cmds_num = argc - 3;
	pipex->cmds = (char **)malloc(sizeof(char *) * pipex->cmds_num);
	if (!pipex->cmds)
		return ;
	pos = 0;
	while (pos < pipex->cmds_num)
	{
		pipex->cmds[pos] = ft_strdup(argv[pos + 2]);
		if (!pipex->cmds[pos])
			free_tab(pipex->cmds, pos);
		pos++;
	}
	(void) pos;
}

void	free_full(t_pipex *pipex)
{
	free(pipex->infile);
	free(pipex->outfile);
	free_tab(pipex->cmds, pipex->cmds_num);
}

void	print_pipex(t_pipex pipex)
{
	int	pos;
	ft_printf("infile = %s, outfile = %s\n", pipex.infile, pipex.outfile);

	pos = 0;
	while (pos < pipex.cmds_num)
	{
		ft_printf("cmd%d = %s ", pos, pipex.cmds[pos]);
		pos++;
	}
	ft_printf("\n");
}

int main(int argc, char *argv[], char *env[])
{
	t_pipex	pipex;
	if (argc < 4)
	{
		ft_dprintf(2, "Usage %s infile cmd1 cmd2 ... cmdn outfile\n", argv[0]);
		exit(0);
	}
	parse_args(&pipex, argc, argv);
	print_pipex(pipex);
	free_full(&pipex);
	(void) env;
}
