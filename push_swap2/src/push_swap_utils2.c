/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 05:09:00 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/28 05:09:01 by tstephan         ###   ########.fr       */
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
