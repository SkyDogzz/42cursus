/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:18:29 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/09 20:08:22 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include <fcntl.h>

typedef struct s_cmd
{
	int		fd;
	char	**args;
}	t_cmd;

typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	t_cmd	*cmds;
	int		cmds_num;
}	t_pipex;

#endif
