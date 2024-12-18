/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:33:22 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/18 15:08:50 by tstephan         ###   ########.fr       */
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

void	get_2(t_inst *inst, t_stack *stack, t_stack *temp)
{
	int		index;
	t_node	*node;

	node = temp->top;
	index = 0;
	while (index++ < 2)
	{
		execpa(inst, stack, pop(temp));
		node = temp->top;
	}
}

void	get_borne(int *min, int *max, t_stack *stack)
{
	t_node	*node;

	if (min != 0)
		*min = INT_MAX;
	if (max != 0)
		*max = INT_MIN;
	node = stack->top;
	if (!node)
		return ;
	while (node)
	{
		if (max != 0 && node->value > *max)
			*max = node->value;
		if (min != 0 && node->value < *min)
			*min = node->value;
		node = node->next;
	}
}

int	get_index(int value, t_stack *stack)
{
	t_node	*node;
	int		pos;

	node = stack->top;
	if (!node)
		return (-1);
	pos = 0;
	while (pos < (int)stack->size)
	{
		if (node->value == value)
			return (pos);
		node = node->next;
		pos++;
	}
	return (-1);
}

int	find_cheapest(t_stack *stack, t_stack *temp)
{
	return (0);
	(void) stack;
	(void) temp;
}

void	get_to_top_a(t_inst *inst, t_stack *stack , int index)
{
	if (index < (int)stack->size / 2)
	{
		while (index--)
			execrra(inst, stack);
	}
	else
	{
		index = stack->size - index;
		while (index--)
			execra(inst, stack);
	}
}

void	get_to_top_b(t_inst *inst, t_stack *stack , int index)
{
	if (index < (int)stack->size / 2)
	{
		while (index--)
			execrra(inst, stack);
	}
	else
	{
		index = stack->size - index;
		while (index--)
			execra(inst, stack);
	}
}
void	move_cheapest(t_inst *inst, t_stack *stack, t_stack *temp, int cheapest)
{
	int	max;

	get_to_top_b(inst, temp, cheapest);
	get_borne(NULL, &max, stack);
	get_to_top_a(inst, stack, get_index(max, stack));
	execpa(inst, stack, pop(temp));
}

void	sort_stack(t_inst *inst, t_stack *stack, t_stack *temp)
{
	int	cheapest;

	if (!stack->top || !stack->top->next)
		return ;
	push_all(inst, stack, temp);
	get_2(inst, stack, temp);
	while (temp->top)
	{
		cheapest = find_cheapest(stack, temp);
		move_cheapest(inst, stack, temp, cheapest);
	}
}
