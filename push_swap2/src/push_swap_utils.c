/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:30:55 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/13 02:42:37 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	execpa(t_inst *inst, t_stack *stack, int value)
{
	push(stack, value);
	add_instruction("pa");
}

void	execpb(t_inst *inst, t_stack *stack, int value)
{
	push(stack, value);
	add_instruction("pb");
}

void	execra(t_inst *inst, t_stack *stack)
{
	rotate(stack);
	add_instruction("ra");
}

void	execrb(t_inst *inst, t_stack *stack)
{
	rotate(stack);
	add_instruction("rb");
}

void	execrra(t_inst *inst, t_stack *stack)
{
	reverse_rotate(stack);
	add_instruction("rra");
}

void	execrrb(t_inst *inst, t_stack *stack)
{
	reverse_rotate(stack);
	add_instruction("rrb");
}
