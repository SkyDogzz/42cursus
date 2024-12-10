/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:43:37 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/10 20:09:13 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"



void	revrotate(t_wrapper *wrapper, t_list **list)
{
	t_list	*act;

	if (!list || !*list)
		return ;
	act = *list;
	while (act->next->next)
		act = act->next;
	ft_lstadd_front(list, ft_lstnew(act->next->content));
	free(act->next);
	act->next = NULL;
	wrapper->count++;
}

void	rotate(t_wrapper *wrapper, t_list **list)
{	
	t_list	*act;
	t_list	*old;

	if (!list || !*list)
		return ;
	act = *list;
	ft_lstadd_back(list, ft_lstnew(act->content));
	old = *list;
	(*list) = (*list)->next;
	free(old);
	wrapper->count++;
}

void	push(t_wrapper *wrapper, t_list **l1, t_list **l2)
{
	t_list	*act;
	t_list	*old;

	if (!l1 || !*l1)
		return ;
	act = *l1;
	ft_lstadd_front(l2, ft_lstnew(act->content));
	old = *l1;
	(*l1) = (*l1)->next;
	free(old);
	wrapper->count++;
}

void	swap(t_wrapper *wrapper, t_list **list)
{
	t_list	*store[3];

	if (!list || !*list || !(*list)->next)
		return ;
	store[0] = *list;
	store[1] = store[0]->next;
	store[2] = store[1]->next;
	*list = store[1];
	(*list)->next = store[0];
	store[0]->next = store[2];
	wrapper->count++;
}
