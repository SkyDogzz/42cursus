/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:21:40 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/11 20:29:12 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	easiest(t_wrapper *wrapper)
{
	if (*(int *)wrapper->l1->content > *(int *)wrapper->l1->next->content)
		rotate(&wrapper->l1, "ra\n");
	return ;
}

int	get_minimum_cost_index(int *cost, int size)
{
	int	min_cost;
	int	min_index;
	int	pos;

	min_cost = cost[0];
	min_index = 0;
	pos = 1;
	while (pos < size)
	{
		if (cost[pos] < min_cost)
		{
			min_cost = cost[pos];
			min_index = pos;
		}
		pos++;
	}
	return (min_index);
}

int	move_to_top(int pos, int size)
{
	if (pos < size / 2)
		return (pos);
	return (-(size - pos));
}

int	ft_abs(int n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

int	move_to_pos(int pos, t_wrapper wrapper)
{
	int	to_pos;
	int	to_place;

	pos = ft_abs(pos);
	while (pos--)
		wrapper.l1 = wrapper.l1->next;
	to_place = *(int *)wrapper.l1->content;
	// ft_printf("to place %d\n", to_place);
	return (to_pos);
}

int	find_cheapest(t_wrapper *wrapper)
{
	t_wrapper	temp;
	int			index;
	int			l1_size;
	int			*cost;
	int			pos;

	l1_size = ft_lstsize(wrapper->l1);
	cost = (int *)malloc(sizeof(int) * l1_size);
	if (!cost)
		return (0);
	temp.l1 = wrapper->l1;
	temp.l2 = wrapper->l2;
	pos = 0;
	while (pos < l1_size)
	{
		int	to_top = move_to_top(pos, l1_size);
		int	to_top_2 = move_to_pos(pos, temp);
		// ft_printf("to top %d\n", to_top);
		pos++;
	}
	index = get_minimum_cost_index(cost, l1_size);
	free(cost);
	return (index);
}

void	better_algo(t_wrapper *wrapper)
{
	t_list	*temp;
	int		size;
	int		cheapest;

	size = ft_lstsize(wrapper->l1);
	if (size == 1)
		return ;
	if (size == 2)
	{
		easiest(wrapper);
		return ;
	}
	else
	{
		push(&wrapper->l1, &wrapper->l2, "pa\n");
		push(&wrapper->l1, &wrapper->l2, "pa\n");
		temp = wrapper->l1;
		while (temp)
		{
			cheapest = find_cheapest(wrapper);
			temp = temp->next;
		}
	}
}
