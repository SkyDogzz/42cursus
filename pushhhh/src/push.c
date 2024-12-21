/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:49:38 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/21 23:02:53 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	execsa(t_wrapper *wrapper)
{
	swap(wrapper->main);
	add_inst(wrapper->inst, "sa\n");
}

void	execsb(t_wrapper *wrapper)
{
	swap(wrapper->temp);
	add_inst(wrapper->inst, "sb\n");
}

void	execss(t_wrapper *wrapper)
{
	swap(wrapper->main);
	swap(wrapper->temp);
	add_inst(wrapper->inst, "ss\n");
}

void	execpa(t_wrapper *wrapper)
{
	push_stack(wrapper->temp, create_node(pop_stack(wrapper->main)));
	add_inst(wrapper->inst, "pa\n");
}

void	execpb(t_wrapper *wrapper)
{
	push_stack(wrapper->main, create_node(pop_stack(wrapper->temp)));
	add_inst(wrapper->inst, "pb\n");
}

void	execra(t_wrapper *wrapper)
{
	rotate_stack(wrapper->main);
	add_inst(wrapper->inst, "ra\n");
}

void	execrb(t_wrapper *wrapper)
{
	rotate_stack(wrapper->temp);
	add_inst(wrapper->inst, "rb\b");
}

void	execrr(t_wrapper *wrapper)
{
	rotate_stack(wrapper->main);
	rotate_stack(wrapper->temp);
	add_inst(wrapper->inst, "rr\n");
}

void	execrra(t_wrapper *wrapper)
{
	rev_rotate_stack(wrapper->main);
	add_inst(wrapper->inst, "rra\n");
}

void	execrrb(t_wrapper *wrapper)
{
	rev_rotate_stack(wrapper->temp);
	add_inst(wrapper->inst, "rrb\b");
}

void	execrrr(t_wrapper *wrapper)
{
	rev_rotate_stack(wrapper->main);
	rev_rotate_stack(wrapper->temp);
	add_inst(wrapper->inst, "rrr\n");
}
