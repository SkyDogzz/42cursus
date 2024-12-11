/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumb_sort3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:34:40 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/11 17:53:09 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_min_index(t_list *list)
{
	int	min;
	int	index;
	int	min_index;

	if (!list)
		return (0);
	min = *(int *)list->content;
	min_index = 0;
	index = 0;
	while (list)
	{
		if (min > *(int *)list->content)
		{
			min = *(int *)list->content;
			min_index = index;
		}
		index++;
		list = list->next;
	}
	return (min_index);
}

static int	find_max_index(t_list *list)
{
	int	max;
	int	index;
	int	max_index;

	if (!list)
		return (0);
	max = *(int *)list->content;
	max_index = 0;
	index = 0;
	while (list)
	{
		if (max < *(int *)list->content)
		{
			max = *(int *)list->content;
			max_index = index;
		}
		index++;
		list = list->next;
	}
	return (max_index);
}

static void	push_min(t_wrapper *wrapper, int min, int size)
{		
	if (min < size / 2 - 1 || min < 1)
		while (min--)
			rotate(&wrapper->l1, "ra\n");
	else
		while (size - min++)
			revrotate(&wrapper->l1, "rra\n");
}

static void	push_max(t_wrapper *wrapper, int max, int size)
{
	if (max < size / 2 - 1 || max < 1)
		while (max--)
			rotate(&wrapper->l1, "ra\n");
	else
		while (size - max++)
			revrotate(&wrapper->l1, "rra\n");
	rotate(&wrapper->l2, "rb\n");
}

void	dumb_sort3(t_wrapper *wrapper)
{
	int	min;
	int	max;
	int	size;

	size = ft_lstsize(wrapper->l1);
	while (wrapper->l1)
	{
		min = find_min_index(wrapper->l1);
		max = find_max_index(wrapper->l1);
		if (get_min(min, size - min - 1) < get_min(max, size - max - 1))
			push_min(wrapper, min, size);
		else
			push_max(wrapper, max, size);
		push(&wrapper->l1, &wrapper->l2, "pa\n");
		size--;
	}
	while (wrapper->l2)
		push(&wrapper->l2, &wrapper->l1, "pb\n");
}
