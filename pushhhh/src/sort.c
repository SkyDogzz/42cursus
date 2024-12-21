/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:19:26 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/21 23:06:15 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_three(t_wrapper *wrapper)
{
	int	node[3];

	node[0] = wrapper->main->top->value;
	node[1] = wrapper->main->top->next->value;
	node[2] = wrapper->main->top->next->next->value;
	if (node[0] < node[1] && node[1] > node[2] && node[2] > node[0])
	{
		execsa(wrapper);
		execra(wrapper);
	}
	else if (node[0] < node[1] && node[1] > node[2] && node[2] < node[0])
		execrra(wrapper);
	else if (node[0] > node[1] && node[1] < node[2] && node[2] < node[0])
		execra(wrapper);
	else if (node[0] > node[1] && node[1] > node[2] && node[2] < node[0])
	{
	execsa(wrapper);
	execrra(wrapper);
	}
	else if (node[0] > node[1] && node[1] < node[2] && node[2] > node[0])
		execsa(wrapper);
}

void	sort_stack(t_wrapper *wrapper)
{
	t_snode	*node;

	if (wrapper->main->size == 2)
	{
		node = wrapper->main->top;
		if (node->value > node->next->value)
			swap(wrapper->main);
		return ;
	}
	if (wrapper->main->size == 3)
	{
		sort_three(wrapper);
		return ;
	}
}
