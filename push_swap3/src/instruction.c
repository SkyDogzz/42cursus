/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:00:03 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/17 17:39:35 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "../include/push_swap.h"

void	add_instruction(t_inst *inst, const char *ins)
{
	t_inode	*new_node;
	t_inode	*temp;

	new_node = malloc(sizeof(t_inode));
	if (!new_node)
		exit_with_error("Memory allocation failed\n");
	new_node->value = ft_strdup(ins);
	new_node->next = NULL;
	if (!inst->top)
		inst->top = new_node;
	else
	{
		temp = inst->top;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
	inst->size++;
}

void	optimize_instructions(t_inst *inst)
{
	(void) inst;
}

void	print_instructions(t_inst *inst)
{
	t_inode	*inode;

	if (!inst->top)
		return ;
	inode = inst->top;
	while (inode)
	{
		ft_printf("%s\n", inode->value);
		inode = inode->next;
	}
}
