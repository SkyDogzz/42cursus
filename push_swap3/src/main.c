/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 03:01:56 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/17 19:24:33 by tstephan         ###   ########.fr       */
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
	while (inst->size)
	{
		temp = current;
		current = current->next;
		free(temp->value);
		free(temp);
		inst->size--;
	}
	free(inst);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack;
	t_stack	*temp;
	t_inst	*inst;

	if (argc == 1)
		exit_with_error("No args\n");
	stack = init_stack();
	temp = init_stack();
	inst = init_inst();
	stack = parse_args(stack, argc, argv);
	print_stack(stack);
	sort_stack(inst, stack, temp);
	optimize_instructions(inst);
	print_instructions(inst);
	print_stack(stack);
	print_stack(temp);
	free_stack(stack);
	free_stack(temp);
	free_inst(inst);
	return (EXIT_SUCCESS);
}
