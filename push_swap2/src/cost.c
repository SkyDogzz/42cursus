/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 05:09:36 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/30 13:10:57 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	min_rotation_cost(const t_stack *stack, int pos)
{
	int	rotate_up;
	int	rotate_down;

	rotate_up = pos;
	rotate_down = (int)stack->size - pos;
	if (rotate_up <= rotate_down)
		return (rotate_up);
	return (rotate_down);
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

int	find_insert_position(t_node *node, int value, t_stack *s2)
{
	const t_node	*next_node;
	int				i;

	i = 0;
	while (node)
	{
		if (node->next)
			next_node = node->next;
		else
			next_node = s2->top;
		if ((node->value > value && value > next_node->value)
			|| (node->value < next_node->value
				&& (value > next_node->value || value < node->value)))
			return (i + 1);
		node = node->next;
		i++;
	}
	return (-1);
}

int	calculate_total_cost(const t_stack *s1, t_stack *s2, int value, int index)
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
