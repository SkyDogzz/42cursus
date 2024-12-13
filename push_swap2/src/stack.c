/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 03:07:25 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/13 06:01:37 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

t_node	*new_node(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node) * 1);
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(stack);
}

void	print_stack(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	if (!node)
		return ;
	while (node)
	{
		ft_printf("%d ", node->value);
		node = node->next;
	}
	ft_printf("\n");
}

int	get_value(t_stack *stack, int index)
{
	t_node	*node;

	if (!stack->top)
		return (0);
	node = stack->top;
	while (index-- > 0 && node->next)
		node = node->next;
	return (node->value);
}
