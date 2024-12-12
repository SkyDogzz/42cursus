/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:30:55 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/12 16:59:21 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	execpa(t_stack *stack, int value)
{
	push(stack, value);
	ft_printf("pa\n");
}

void	execpb(t_stack *stack, int value)
{
	push(stack, value);
	ft_printf("pb\n");
}

void	execra(t_stack *stack)
{
	rotate(stack);
	ft_printf("ra\n");
}

void	execrb(t_stack *stack)
{
	rotate(stack);
	ft_printf("rb\n");
}

void	execrra(t_stack *stack)
{
	reverse_rotate(stack);
	ft_printf("rra\n");
}

void	execrrb(t_stack *stack)
{
	reverse_rotate(stack);
	ft_printf("rrb\n");
}
