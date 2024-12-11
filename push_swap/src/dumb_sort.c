/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumb_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:18:09 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/11 17:16:09 by tstephan         ###   ########.fr       */
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

void	dumb_sort(t_wrapper *wrapper)
{
	int	min;

	while (wrapper->l1)
	{
		min = find_min_index(wrapper->l1);
		while (min-- > 0)
			rotate(&wrapper->l1, "ra\n");
		push(&wrapper->l1, &wrapper->l2, "pa\n");
	}
	while (wrapper->l2)
	{
		push(&wrapper->l2, &wrapper->l1, "pb\n");
	}
}
