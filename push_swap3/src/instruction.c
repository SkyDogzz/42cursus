/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:00:03 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/17 19:35:40 by tstephan         ###   ########.fr       */
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

void	remove_node(t_inst *inst, t_inode *previous)
{
	t_inode	*tmp;

	if (!inst || !inst->top)
		return;
	if (!previous)
	{
		tmp = inst->top;
		inst->top = inst->top->next;
	}
	else
	{
		tmp = previous->next;
		if (!tmp)
			return;
		previous->next = tmp->next;
	}
	free(tmp->value);
	free(tmp);
	inst->size--;
}

void	optimize_instructions(t_inst *inst)
{
	t_inode	*previous;
	t_inode	*node;
	int		optimized;

	optimized = 1;
	while (optimized)
	{
		optimized = 0;
		node = inst->top;
		previous = NULL;
		if (!node)
			break;
		while (node && node->next)
		{
			if (previous)
				if ((!ft_strncmp(node->value, "pb", 2) && !ft_strncmp(node->next->value, "pa", 2))|
				(!ft_strncmp(node->value, "pa", 2) && !ft_strncmp(node->next->value, "pb", 2)))
				{
					remove_node(inst, previous);
					remove_node(inst, previous);
					optimized = 1;
					node = (previous) ? previous->next : inst->top;
				}
			previous = node;
			node = node->next;
		}
	}
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
