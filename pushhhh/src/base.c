/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:49:31 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/20 19:16:08 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_stack(t_stack *stack)
{
	t_snode	*memfirst;

	memfirst = get_node(stack, 0);
	stack->top = stack->top->next;
	get_node(stack, stack->size - 2)->next = memfirst;
	memfirst->next = NULL;
}

void	rev_rotate_stack(t_stack *stack)
{
	t_snode	*memfirst;

	memfirst = get_node(stack, 0);
	stack->top = get_node(stack, stack->size - 1);
	stack->top->next = memfirst;
	get_node(stack, stack->size - 1)->next = NULL;
}

void	swap(t_stack *stack)
{
	t_snode	*memfirst;
	t_snode	*memthird;

	memfirst = get_node(stack, 0);
	memthird = get_node(stack, 2);
	stack->top = stack->top->next;
	stack->top->next = memfirst;
	memfirst->next = memthird;
}
