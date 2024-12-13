/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:56:05 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/13 02:00:28 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>

int	index_of(t_stack *stack, int value)
{
	t_node	*node;
	int		idx;

	node = stack->top;
	idx = 0;
	while (node)
	{
		if (node->value == value)
			return (idx);
		node = node->next;
		idx++;
	}
	return (-1);
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
		if (node->value < *min)
			*min = node->value;
		node = node->next;
	}
}

int	find_insert_position(t_node *node, int value, t_stack *s2)
{
	t_node	*next_node;
	int		i;

	i = 0;
	while (node)
	{
		if (node->next)
			next_node = node->next;
		else
			next_node = s2->top;
		if ((node->value < value && value < next_node->value)
			|| (node->value > next_node->value
				&& (value < next_node->value || value > node->value)))
			return (i + 1);
		node = node->next;
		i++;
	}
	return (-1);
}

int	insertion_index(t_stack *s2, int value)
{
	int		min;
	int		max;
	int		pos;

	if (!s2->top)
		return (0);
	get_borne(s2, &min, &max);
	pos = find_insert_position(s2->top, value, s2);
	if (pos != -1)
		return (pos);
	pos = index_of(s2, max) + 1;
	if (pos >= (int)s2->size)
		return (0);
	return (pos);
}

int	min_rotation_cost(t_stack *stack, int pos)
{
	int	rotate_up;
	int	rotate_down;

	rotate_up = pos;
	rotate_down = (int)stack->size - pos;
	if (rotate_up <= rotate_down)
		return (rotate_up);
	return (rotate_down);
}

int	calculate_total_cost(t_stack *s1, t_stack *s2, int value, int index)
{
	t_cheap	cheap;

	cheap.value = value;
	cheap.insert_pos = insertion_index(s2, cheap.value);
	cheap.cost_s1 = min_rotation_cost(s1, index);
	cheap.cost_s2 = min_rotation_cost(s2, cheap.insert_pos);
	return (cheap.cost_s1 + cheap.cost_s2);
}

int	find_cheapest(t_stack *s1, t_stack *s2)
{
	t_node	*node;
	int		i;
	int		best_index;
	int		best_cost;
	int		current_cost;

	if (!s1->top)
		return (-1);
	best_cost = INT_MAX;
	best_index = 0;
	node = s1->top;
	i = 0;
	while (node)
	{
		current_cost = calculate_total_cost(s1, s2, node->value, i);
		if (current_cost < best_cost)
		{
			best_cost = current_cost;
			best_index = i;
		}
		node = node->next;
		i++;
	}
	return (best_index);
}

void	get_on_top(t_stack *stack, int value)
{
	t_node	*node;
	int		index;
	int		i;

	node = stack->top;
	index = 0;
	while (node)
	{
		if (node->value == value)
			break ;
		node = node->next;
		index++;
	}
	if (index < (int)stack->size / 2)
	{
		i = index;
		while (i--)
			execrb(stack);
	}
	else
	{
		i = (int)stack->size - index;
		while (i--)
			execrrb(stack);
	}
}

void	rotate_to_top(t_stack *stack, int index, void (*rotate)(t_stack *),
	void (*rev_rotate)(t_stack *))
{
	int	iter;

	if (index < (int)stack->size / 2)
	{
		iter = index;
		while (iter--)
			rotate(stack);
	}
	else
	{
		iter = (int)stack->size - index;
		while (iter--)
			rev_rotate(stack);
	}
}

void	move_cheapest(int index, t_stack *stack, t_stack *temp)
{
	int	value;
	int	insert_pos;

	rotate_to_top(stack, index, execra, execrra);
	value = get_value(stack, 0);
	insert_pos = insertion_index(temp, value);
	rotate_to_top(temp, insert_pos, execrb, execrrb);
	execpb(temp, pop(stack));
}

void	repush(t_stack *stack, t_stack *temp)
{
	int	min;
	int	max;

	get_borne(temp, &min, &max);
	get_on_top(temp, max);
	while (temp->top)
		execpb(stack, pop(temp));
}

void	sort_stack(t_stack *stack, t_stack *temp)
{
	int	cheapest_index;

	if (!stack->top)
		return ;
	if (stack->top->next)
		execpa(temp, pop(stack));
	if (stack->top)
		execpa(temp, pop(stack));
	while (stack->top)
	{
		cheapest_index = find_cheapest(stack, temp);
		move_cheapest(cheapest_index, stack, temp);
	}
	repush(stack, temp);
	execrra(stack);
}
