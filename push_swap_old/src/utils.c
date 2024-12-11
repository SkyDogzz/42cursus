/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:43:37 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/11 15:45:43 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	revrotate(t_wrapper *wrapper, int l)
{
	t_list	*act;

	act = wrapper->l2;
	if (l == 1)
		act = wrapper->l1;
	if (!act)
		return ;
	while (act->next->next)
		act = act->next;
	ft_lstadd_front(&act, ft_lstnew(act->next->content));
	free(act->next);
	act->next = NULL;
	wrapper->count++;
}

void	rotate(t_wrapper *wrapper, int l)
{	
	t_list	*act;
	t_list	*old;

	act = wrapper->l2;
	if (l == 1)
		act = wrapper->l1;
	if (!act)
		return ;
	ft_lstadd_back(&act, ft_lstnew(act->content));
	old = act;
	act = act->next;
	free(old);
	wrapper->count++;
}

void	push(t_wrapper *wrapper, int orig)
{
	t_list	*old;
	t_list *l1;
	t_list *l2;

	l1 = wrapper->l2;
	l2 = wrapper->l1;
	if (orig == 1)
	{	
		l1 = wrapper->l1;
		l2 = wrapper->l2;
	}
	if (!l1)
		return ;
	ft_lstadd_front(&l2, ft_lstnew(l1->content));
	old = l1;
	l1 = l1->next;
	free(old);
	wrapper->count++;
}

void	swap(t_wrapper *wrapper, int l)
{
	t_list	*act;
	t_list	*store[3];

	act = wrapper->l2;
	if (l == 1)
		act = wrapper->l1;
	if (!act)
		return ;
	store[0] = act;
	store[1] = store[0]->next;
	store[2] = store[1]->next;
	act = store[1];
	act->next = store[0];
	store[0]->next = store[2];
	wrapper->count++;
}
