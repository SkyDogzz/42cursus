/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:56:05 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/12 14:09:48 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_cheapest(t_stack *s1, t_stack *s2)
{
	return (0);
	(void) s1;
	(void) s2;
}

void	move_cheapest(int index, t_stack *stack, t_stack *temp)
{
	while (index--)
		rotate(stack);
	push(temp, pop(stack));
}

void	repush(t_stack *stack, t_stack *temp)
{
	while (temp->top)
		push(stack, pop(temp));
}

void	sort_stack(t_stack *stack, t_stack *temp)
{
	int	cheapest_index;

	push(temp, pop(stack));
	push(temp, pop(stack));
	cheapest_index = find_cheapest(stack , temp);
	move_cheapest(cheapest_index, stack, temp);
	repush(stack, temp);
}
