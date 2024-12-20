/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:44:23 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/20 20:13:29 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# include <stddef.h>
# include "../libft/include/libft.h"

typedef struct s_inode
{
	char			*value;
	struct s_inode	*next;
}	t_inode;

typedef struct s_inst
{
	t_inode	*top;
	size_t	size;
}	t_inst;

t_inst	*create_inst(void);
t_inode	*create_inode(char *value);
void	free_inst(t_inst *inst);
void	add_inst(t_inst *inst, char *value);
void	print_inst(t_inst *inst);

#endif
