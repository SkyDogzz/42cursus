/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 05:09:36 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/28 05:16:46 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
