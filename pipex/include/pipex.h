/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:18:29 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/09 18:48:43 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"

typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	char	**cmds;
	int		cmds_num;
}	t_pipex;

#endif
