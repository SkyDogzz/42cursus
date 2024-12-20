/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:05:58 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/20 18:52:59 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
	{
		ft_dprintf(2, "Failed to malloc stack\n");
		return (NULL);
	}
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

t_bool	is_empty_stack(t_stack *stack)
{
	if (!stack || !stack->top)
		return (TRUE);
	return (FALSE);
}

int	size_stack(t_stack	*stack)
{
	if (!stack->top)
		return (0);
	return (stack->size);
}

t_snode	*create_node(int value)
{
	t_snode	*node;

	node = (t_snode *)malloc(sizeof(t_snode));
	if (!node)
	{
		ft_dprintf(2, "Failed to malloc node\n");
		return (NULL);
	}
	node->value = value;
	node->next = NULL;
	return (node);
}

t_bool	push_stack(t_stack *stack, t_snode *node)
{
	t_snode	*mem;

	if (!stack || !node)
	{
		ft_dprintf(2, "Failed to push node on stack\n");
		return (FALSE);
	}
	mem = stack->top;
	stack->top = node;
	stack->top->next = mem;
	stack->size++;
		return (TRUE);
}

int	pop_stack(t_stack	*stack)
{
	int		popped;
	t_snode	*mem;

	if (!stack || !stack->top)
	{
		ft_dprintf(2, "Failed to pop stack\n");
		return (0);
	}
	mem = stack->top;
	popped = mem->value;
	stack->top = stack->top->next;
	free(mem);
	stack->size--;
	return (popped);
}

void	print_stack(t_stack *stack)
{
    t_snode	*current;

    if (is_empty_stack(stack))
    {
        ft_printf("Stack is empty\n");
        return;
    }
    current = stack->top;
    while (current != NULL)
    {
        ft_printf("%d ", current->value);
        current = current->next;
    }
    ft_printf("\n");
}

void	free_stack(t_stack *stack)
{
	t_snode *current;
	t_snode	*next;

	next = stack->top;
	while (next)
	{
		current = next;
		next = current->next;
		free(current);
	}
	free(stack);
}

t_snode	*get_node(t_stack *stack, int index)
{
	t_snode	*current;

	current = stack->top;
	while (index--)
		current = current->next;
	return (current);
}
