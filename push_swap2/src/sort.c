/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:56:05 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/28 10:36:07 by tstephan         ###   ########.fr       */
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

void	sort_three(t_inst *inst, t_stack *stack)
{
	int	node[3];

	node[0] = stack->top->value;
	node[1] = stack->top->next->value;
	node[2] = stack->top->next->next->value;
	if (node[0] < node[1] && node[1] > node[2] && node[2] > node[0])
	{
		execsa(inst, stack);
		execra(inst, stack);
	}
	else if (node[0] > node[1] && node[1] < node[2] && node[2] > node[0])
		execsa(inst, stack);
	else if (node[0] < node[1] && node[1] > node[2] && node[2] < node[0])
		execrra(inst, stack);
	else if (node[0] > node[1] && node[1] < node[2] && node[2] < node[0])
		execra(inst, stack);
	else if (node[0] > node[1] && node[1] > node[2] && node[2] < node[0])
	{
		execsa(inst, stack);
		execrra(inst, stack);
	}
}

void	sort_five(t_inst *inst, t_stack *stack, t_stack *temp)
{
	int	min;
	int	max;

	while (stack->size > 3)
	{
		get_borne(stack, &min, &max);
		get_on_topa(inst, stack, min);
		execpb(inst, temp, pop(stack));
	}
	sort_three(inst, stack);
	execpa(inst, stack, pop(temp));
	execpa(inst, stack, pop(temp));
}

void	sort_stack(t_inst *inst, t_stack *stack, t_stack *temp)
{
	int	cheapest_index;

	if (stack->size < 2)
		return ;
	if (stack->size == 2)
	{
		if (stack->top->value > stack->top->next->value)
			execra(inst, stack);
		return ;
	}
	if (stack->size == 3)
		return (sort_three(inst, stack));
	if (stack->size <= 5)
		return (sort_five(inst, stack, temp));
	while (stack->size)
	{
		cheapest_index = find_cheapest(stack, temp);
		move_cheapest(inst, cheapest_index, stack, temp);
	}
	if (temp->size > 0)
		repush(inst, stack, temp);
}
