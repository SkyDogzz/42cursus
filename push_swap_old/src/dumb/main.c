/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:37:04 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/11 15:36:46 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int		find_min_index(t_wrapper *wrapper, int l)
{
	int index;
	int	pos;
	int	min;
	int	*temp;
	t_list *act;

	pos = 0;
	index = 0;
	act = wrapper->l2;
	if (l == 1)
		act = wrapper->l1;
	min = *(int *)act->content;
	while (act)
	{
		temp = act->content;
		if (*temp < min)
		{
			min = *temp;
			index = pos;
		}
		act = act->next;
		pos++;
	}
	return (index);
}

int		find_max_index(t_wrapper *wrapper, int l)
{
	int index;
	int	pos;
	int	max;
	int	*temp;
	t_list *act;

	pos = 0;
	index = 0;
	act = wrapper->l2;
	if (l == 1)
		act = wrapper->l1;
	max = *(int *)act->content;
	while (act)
	{
		temp = act->content;
		if (*temp > max)
		{
			max = *temp;
			index = pos;
		}
		act = act->next;
		pos++;
	}
	return (index);
}

void	dumb_sort(t_wrapper *wrapper)
{
	int	index;
	while (wrapper->l1)
	{
		index = find_min_index(wrapper, 1);
		while (index--)
			rotate(wrapper, 1);
		push(wrapper, 1);
	}
	while (wrapper->l2)
		push(wrapper, 2);
}

void	dumb_sort_2(t_wrapper *wrapper)
{
	int	index;
	int	size;

	size = ft_lstsize(wrapper->l1);
	while (wrapper->l1)
	{
		index = find_min_index(wrapper, 1);
		if (index < size / 2 || index < 1)
			while (index--)
				rotate(wrapper, 1);
		else
			while (size - index++)
				revrotate(wrapper, 1);
		push(wrapper, 1);
		size--;
	}
	while (wrapper->l2)
		push(wrapper, 2);
}
