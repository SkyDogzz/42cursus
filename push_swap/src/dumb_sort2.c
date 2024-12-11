/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumb_sort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:46:32 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/11 17:34:18 by tstephan         ###   ########.fr       */
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

void	dumb_sort2(t_wrapper *wrapper)
{
	int	min;
	int	size;

	while (wrapper->l1)
	{
		min = find_min_index(wrapper->l1);
		size = ft_lstsize(wrapper->l1);
		if (min < size / 2 - 1 || min < 1)
			while (min--)
				rotate(&wrapper->l1, "ra\n");
		else
			while (size - min++)
				revrotate(&wrapper->l1, "rra\n");
		push(&wrapper->l1, &wrapper->l2, "pa\n");
		size--;
	}
	while (wrapper->l2)
		push(&wrapper->l2, &wrapper->l1, "pb\n");
}
