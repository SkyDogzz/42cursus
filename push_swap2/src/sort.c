/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:56:05 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/28 05:17:58 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>

void	rotate_to_top(t_inst *inst, t_stack *stack, int index, void (*rotate)
	(t_inst *, t_stack *), void (*rev_rotate)(t_inst *, t_stack *))
{
	int	iter;

	if (index < (int)stack->size / 2)
	{
		iter = index;
		while (iter--)
			rotate(inst, stack);
	}
	else
	{
		iter = (int)stack->size - index;
		while (iter--)
			rev_rotate(inst, stack);
	}
}

void	move_cheapest(t_inst *inst, int index, t_stack *stack, t_stack *temp)
{
	int	value;
	int	insert_pos;

	rotate_to_top(inst, stack, index, execra, execrra);
	value = get_value(stack, 0);
	insert_pos = insertion_index(temp, value);
	rotate_to_top(inst, temp, insert_pos, execrb, execrrb);
	execpb(inst, temp, pop(stack));
}

void	repush(t_inst *inst, t_stack *stack, t_stack *temp)
{
	int	min;
	int	max;

	get_borne(temp, &min, &max);
	get_on_top(inst, temp, max);
	while (temp->top)
		execpa(inst, stack, pop(temp));
}

void	sort_stack(t_inst *inst, t_stack *stack, t_stack *temp)
{
	int	cheapest_index;

	if (!stack->top)
		return ;
	if (stack->top->next)
		execpb(inst, temp, pop(stack));
	if (stack->top)
		execpb(inst, temp, pop(stack));
	while (stack->top)
	{
		cheapest_index = find_cheapest(stack, temp);
		move_cheapest(inst, cheapest_index, stack, temp);
	}
	repush(inst, stack, temp);
}
