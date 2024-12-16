/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:30:55 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/13 07:29:56 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	execpa(t_inst *inst, t_stack *stack, int value)
{
	push(stack, value);
	add_instruction(inst, "pa");
}

void	execpb(t_inst *inst, t_stack *stack, int value)
{
	push(stack, value);
	add_instruction(inst, "pb");
}

void	execra(t_inst *inst, t_stack *stack)
{
	rotate(stack);
	add_instruction(inst, "ra");
}

void	execrb(t_inst *inst, t_stack *stack)
{
	rotate(stack);
	add_instruction(inst, "rb");
}

void	execrra(t_inst *inst, t_stack *stack)
{
	reverse_rotate(stack);
	add_instruction(inst, "rra");
}

void	execrrb(t_inst *inst, t_stack *stack)
{
	reverse_rotate(stack);
	add_instruction(inst, "rrb");
}
