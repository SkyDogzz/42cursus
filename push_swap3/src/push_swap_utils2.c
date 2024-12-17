/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:30:55 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/17 17:40:47 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
