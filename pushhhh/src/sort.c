/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:19:26 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/22 03:36:02 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_three(t_wrapper *wrapper)
{
	int	node[3];

	node[0] = wrapper->main->top->value;
	node[1] = wrapper->main->top->next->value;
	node[2] = wrapper->main->top->next->next->value;
	if (node[0] < node[1] && node[1] > node[2] && node[2] < node[0])
		execrra(wrapper);
	else if (node[0] > node[1] && node[1] < node[2] && node[2] < node[0])
		execra(wrapper);
	else if (node[0] > node[1] && node[1] < node[2] && node[2] > node[0])
		execsa(wrapper);
	else if (node[0] < node[1] && node[1] > node[2] && node[2] > node[0])
	{
		execsa(wrapper);
		execra(wrapper);
	}
	else if (node[0] > node[1] && node[1] > node[2] && node[2] < node[0])
	{
		execsa(wrapper);
		execrra(wrapper);
	}
}

void	first_part_sort(t_wrapper *wrapper)
{
	while (wrapper->main->size > 3)
		execpb(wrapper);
}

void	get_borne(t_stack *stack, int *min, int *max)
{
	t_snode	*node;

	if (min)
		*min = INT_MAX;
	if (max)
		*max = INT_MIN;
	node = stack->top;
	while (node)
	{
		if (min && *min > node->value)
			*min = node->value;
		if (max && *max < node->value)
			*max = node->value;
		node = node->next;
	}
}

// TODO
int	find_cheapest(t_wrapper *wrapper)
{
	return (0);
}

void	move_cheapest(t_wrapper *wrapper, int cheapest)
{
	int	min;
	int	max;

	get_borne(wrapper->main, &min, &max);
	if (wrapper )
}

void	second_part_sort(t_wrapper *wrapper)
{
	int	cheapest;

	while (wrapper->temp->size)
	{
		cheapest = find_cheapest(wrapper);
		move_cheapest(wrapper, cheapest);
	}
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
	first_part_sort(wrapper);
	second_part_sort(wrapper);
}
