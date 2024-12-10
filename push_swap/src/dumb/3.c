/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:36:27 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/10 20:56:23 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	get_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
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
		if (get_min(indexmin, size - indexmin) < get_min(indexmax, size - indexmax))
		{
			if (indexmin < size / 2 || indexmin < 1)
				while (indexmin--)
					rotate(wrapper, l1);
			else
				while (size - indexmin++)
					revrotate(wrapper, l1);
			push(wrapper, l1, l2);
			size--;
		}
		else
		{
			if (indexmax < size / 2 || indexmax < 1)
				while (indexmax--)
					rotate(wrapper, l1);
			else
				while (size - indexmax++)
					revrotate(wrapper, l1);
			push(wrapper, l1, l2);
			rotate(wrapper, l2);
			size--;
		}
	}
	indexmax = find_max_index(*l2);
	while(indexmax--)
		rotate(wrapper, l2);
	while (*l2)
		push(wrapper, l2, l1);
}
