/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 05:10:33 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/28 05:30:41 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	get_on_top(t_inst *inst, t_stack *stack, int value)
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
			execrb(inst, stack);
	}
	else
	{
		i = (int)stack->size - index;
		while (i--)
			execrrb(inst, stack);
	}
}
