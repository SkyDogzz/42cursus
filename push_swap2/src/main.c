/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 03:01:56 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/28 06:24:12 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exit_with_error(const char *error)
{
	ft_dprintf(2, "%s", error);
	exit(EXIT_FAILURE);
}

t_inst	*init_inst(void)
{
	t_inst	*inst;

	inst = (t_inst *)malloc(sizeof(t_inst) * 1);
	if (!inst)
		return (NULL);
	inst->top = NULL;
	inst->size = 0;
	return (inst);
}

void	free_inst(t_inst *inst)
{
	t_inode	*current;
	t_inode	*temp;

	if (!inst)
		return ;
	current = inst->top;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp->value);
		free(temp);
	}
	free(inst);
}

t_bool	already_ordered(t_stack *stack)
{
	t_node	*node;
	int		act;

	node = stack->top;
	act = node->value;
	node = node->next;
	if (!node)
		return (TRUE);
	while (node)
	{
		if (node->value < act)
			return (FALSE);
		act = node->value;
		node = node->next;
	}
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack;
	t_stack	*temp;
	t_inst	*inst;

	if (argc == 1)
		exit_with_error("");
	stack = init_stack();
	temp = init_stack();
	inst = init_inst();
	stack = parse_args(stack, argc, argv);
	if (!stack)
	{
		free_stack(temp);
		free_inst(inst);
		exit_with_error("Error\n");
	}
	if (!already_ordered(stack))
		sort_stack(inst, stack, temp);
	print_instructions(inst);
	free_stack(stack);
	free_stack(temp);
	free_inst(inst);
	return (EXIT_SUCCESS);
}
