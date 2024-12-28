/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 04:05:33 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/28 07:05:45 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack *stack, int value)
{
	t_node	*node;

	node = new_node(value);
	node->next = stack->top;
	stack->top = node;
	stack->size++;
}

int	pop(t_stack *stack)
{
	t_node	*node;
	int		value;

	if (!stack->top)
		return (0);
	node = stack->top;
	value = node->value;
	stack->top = node->next;
	free(node);
	stack->size--;
	return (value);
}

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	first = stack->top;
	second = stack->top->next;
	first->next = second->next;
	stack->top = second;
	second->next = first;
}

void	rotate(t_stack *stack)
{
	t_node	*temp;
	t_node	*current;

	if (stack->size < 2)
		return ;
	temp = stack->top;
	stack->top = stack->top->next;
	current = stack->top;
	while (current->next)
		current = current->next;
	current->next = temp;
	temp->next = NULL;
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*current;
	t_node	*prev;

	if (stack->size < 2)
		return ;
	current = stack->top;
	prev = NULL;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	if (prev)
		prev->next = NULL;
	current->next = stack->top;
	stack->top = current;
}
