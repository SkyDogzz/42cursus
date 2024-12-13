/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:56:05 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/13 01:31:46 by skydogzz         ###   ########.fr       */
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

int	insertion_index(t_stack *s2, int value)
{
	int		min;
	int		max;
	t_node	*node;
	t_node	*next_node;
	int		i;

	if (!s2->top)
		return (0);
	get_borne(s2, &min, &max);
	node = s2->top;
	i = 0;
	while (node)
	{
		next_node = node->next;
		if (!next_node)
			next_node = s2->top;
		if ((node->value < value && value < next_node->value) 
			|| (node->value > next_node->value && (value \
			< next_node->value || value > node->value)))
				return (i + 1);
		node = node->next;
		i++;
	}
	{
		int max_i = index_of(s2, max);
		return (max_i + 1 >= (int)s2->size) ? 0 : max_i + 1;
	}
}

int	min_rotation_cost(t_stack *stack, int pos)
{
	int rotate_up = pos;
	int rotate_down = (int)stack->size - pos;
	return (rotate_up < rotate_down) ? rotate_up : rotate_down;
}

int	find_cheapest(t_stack *s1, t_stack *s2)
{
	t_node	*node;
	int		i;
	int		best_index;
	int		best_cost;

	if (!s1->top)
		return (-1);

	best_cost = INT_MAX;
	best_index = 0;
	node = s1->top;
	i = 0;
	while (node)
	{
		int value = node->value;
		int insert_pos = insertion_index(s2, value);
		int cost_s1 = min_rotation_cost(s1, i);
		int cost_s2 = min_rotation_cost(s2, insert_pos);
		int total_cost = cost_s1 + cost_s2;

		if (total_cost < best_cost)
		{
			best_cost = total_cost;
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

void	move_cheapest(int index, t_stack *stack, t_stack *temp)
{
	int	min;
	int	max;
	int	value;
	int	iter;

	iter = index;
	if (iter < (int)stack->size / 2)
		while (iter--)
			execra(stack);
	else
	{
		iter = (int)stack->size - iter;
		while (iter--)
			execrra(stack);
	}
	min = 0;
	max = 0;
	get_borne(temp, &min, &max);
	value = get_value(stack, 0);
	{
		int insert_pos = insertion_index(temp, value);
		if (insert_pos < (int)temp->size / 2)
		{
			int r = insert_pos;
			while (r--)
				execrb(temp);
		}
		else
		{
			int r = (int)temp->size - insert_pos;
			while (r--)
				execrrb(temp);
		}
	}
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
