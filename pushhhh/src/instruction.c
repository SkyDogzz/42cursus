/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:51:36 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/20 20:11:44 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_inst	*create_inst(void)
{
	t_inst	*inst;

	inst = (t_inst *)malloc(sizeof(t_inst));
	if (!inst)
	{
		ft_dprintf(2, "Failed to malloc inst\n");
		return (NULL);
	}
	inst->top = NULL;
	inst->size = 0;
	return (inst);
}

t_inode	*create_inode(char *value)
{
t_inode	*node;

	node = (t_inode *)malloc(sizeof(t_inode));
	if (!node)
	{
		ft_dprintf(2, "Failed to malloc inst node\n");
		return (NULL);
	}
	node->value = ft_strdup(value);
	node->next = NULL;
	return (node);
}

void	free_inst(t_inst *inst)
{
	t_inode *current;
	t_inode	*next;

	next = inst->top;
	while (next)
	{
		current = next;
		next = current->next;
		free(current->value);
		free(current);
	}
	free(inst);
}

void	add_inst(t_inst *inst, char *value)
{
	t_inode	*node;

	if (inst->top == NULL)
	{
		inst->top = create_inode(value);
		inst->size++;
		return ;
	}
	node = inst->top;
	while (node && node->next)
		node = node->next;
	node->next = create_inode(value);
	inst->size++;
}

void	print_inst(t_inst *inst)
{
	t_inode	*current;

	current = inst->top;
	while (current)
	{
		ft_printf("%s\n", current->value);
		current = current->next;
	}
}
