/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:33:22 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/17 19:46:04 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h" 

void	push_all(t_inst *inst, t_stack *stack, t_stack *temp)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		execpb(inst, temp, pop(stack));
		node = stack->top;
	}
}

void	move_cheapest(t_inst *inst, t_stack *stack, t_stack *temp)
{
	execpa(inst, stack, pop(temp));
}

void	sort_stack(t_inst *inst, t_stack *stack, t_stack *temp)
{
	push_all(inst, stack, temp);
	while (temp->top)
		move_cheapest(inst, stack, temp);
}
