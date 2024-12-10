/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:37:04 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/10 20:29:54 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int		find_min_index(t_list *list)
{
	int index;
	int	pos;
	int	min;
	int	*temp;

	pos = 0;
	index = 0;
	t_list *act = list;
	min = *(int *)list->content;
	while (list)
	{
		temp = list->content;
		if (*temp < min)
		{
			min = *temp;
			index = pos;
		}
		list = list->next;
		pos++;
	}
	return (index);
}

int		find_max_index(t_list *list)
{
	int index;
	int	pos;
	int	max;
	int	*temp;

	pos = 0;
	index = 0;
	t_list *act = list;
	max = *(int *)list->content;
	while (list)
	{
		temp = list->content;
		if (*temp > max)
		{
			max = *temp;
			index = pos;
		}
		list = list->next;
		pos++;
	}
	return (index);
}

void	dumb_sort(t_wrapper *wrapper, t_list **l1, t_list **l2)
{
	int	index;
	while (*l1)
	{
		index = find_min_index(*l1);
		while (index--)
			rotate(wrapper, l1);
		push(wrapper, l1, l2);
	}
	while (*l2)
		push(wrapper, l2, l1);
}

void	dumb_sort_2(t_wrapper *wrapper, t_list **l1, t_list **l2)
{
	int	index;
	int	size;

	size = ft_lstsize(*l1);
	while (*l1)
	{
		index = find_min_index(*l1);
		if (index < size / 2 || index < 1)
			while (index--)
				rotate(wrapper, l1);
		else
			while (size - index++)
				revrotate(wrapper, l1);
		push(wrapper, l1, l2);
		size--;
	}
	while (*l2)
		push(wrapper, l2, l1);
}

void	dumb_sort_3(t_wrapper *wrapper, t_list **l1, t_list **l2)
{
	int	indexmin;
	int	indexmax;
	int	size;

	size = ft_lstsize(*l1);
	while (*l1)
	{
		indexmin = find_min_index(*l1);
		indexmax = find_max_index(*l1);
		push(wrapper, l1, l2);
	}
	while (*l2)
		push(wrapper, l2, l1);
}
