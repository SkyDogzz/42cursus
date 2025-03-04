/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:43:37 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/11 16:50:41 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_list(t_list *list)
{
	t_list	*temp;

	while (list && list->content)
	{
		temp = list;
		free(list->content);
		list = list->next;
		free(temp);
	}
}

void	free_wrapper(t_wrapper *wrapper)
{
	free_list(wrapper->l1);
	free_list(wrapper->l2);
}
