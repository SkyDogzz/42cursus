/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:56:05 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/12 17:30:35 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_cheapest(t_stack *s1, t_stack *s2)
{
	return (s1->size - 1);
	(void) s1;
	(void) s2;
}

void	get_borne(t_stack *stack, int *min, int *max)
{
	t_node	*node;

	if (!stack->top)
		return ;
	node = stack->top;
	*min = node->value;
	*max = node->value;
	while (node)
	{
		if (node->value > *max)
			*max = node->value;
		if (node ->value < *min)
			*min = node->value;
		node = node->next;
	}
}

void	get_on_top(t_stack *stack, int value)
{
	t_node	*node;
	int		index;

	node = stack->top;
	index = 0;
	while (node)
	{
		if (node->value == value)
			break ;
		node = node->next;
		index++;
	}
	if (index < stack->size / 2)
		while (index--)
			execrb(stack);
	else
	{
		index = stack->size - index;
		while (index--)
			execrrb(stack);
	}
}

int	get_closest(t_stack *stack, int value)
{
	t_node	*node;
	int		closest;

	node = stack->top;
	closest = node->value;
	while (node)
	{
		if (closest > value && node->value < value)
			closest = node->value;
		if (node->value > closest && node->value < value)
			closest = node->value;
		node = node->next;
	}
	return (closest);
}

void	move_cheapest(int index, t_stack *stack, t_stack *temp)
{
	int	min;
	int	max;
	int	value;
	int	iter;

	iter = index;
	if (iter < stack->size / 2)
		while (iter--)
			execra(stack);
	else
	{
		iter = stack->size - iter;
		while (iter--)
			execrra(stack);
	}
	min = 0;
	max = 0;
	get_borne(temp, &min, &max);
	value = get_value(stack, index);
	if (value > min && value < max)
		get_on_top(temp, get_closest(temp, value));
	else
		get_on_top(temp, max);
	execpb(temp, pop(stack));
}

void	repush(t_stack *stack, t_stack *temp)
{
	while (temp->top)
		execpb(stack, pop(temp));
}

void	sort_stack(t_stack *stack, t_stack *temp)
{
	int	max;
	int	min;
	int	cheapest_index;

	execpa(temp, pop(stack));
	execpa(temp, pop(stack));
	while (stack->top)
	{
		cheapest_index = find_cheapest(stack, temp);
		move_cheapest(cheapest_index, stack, temp);
	}
	get_borne(temp, &min, &max);
	get_on_top(temp, max);
	repush(stack, temp);
}
