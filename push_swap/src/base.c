/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:50:01 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/11 17:13:55 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	revrotate(t_list **list, const char *s)
{
	t_list	*act;

	ft_printf("%s", s);
	if (!list || !*list)
		return ;
	act = *list;
	while (act->next->next)
		act = act->next;
	ft_lstadd_front(list, ft_lstnew(act->next->content));
	free(act->next);
	act->next = NULL;
}

void	rotate(t_list **list, const char *s)
{	
	t_list	*old;

	ft_printf("%s", s);
	if (!list || !*list)
		return ;
	ft_lstadd_back(list, ft_lstnew((*list)->content));
	old = *list;
	*list = (*list)->next;
	free(old);
}

void	push(t_list **l1, t_list **l2, const char *s)
{
	t_list	*old;

	ft_printf("%s", s);
	if (!l1 || !*l1)
		return ;
	ft_lstadd_front(l2, ft_lstnew((*l1)->content));
	old = *l1;
	*l1 = (*l1)->next;
	free(old);
}

void	swap(t_list **list, const char *s)
{
	t_list	*store[3];

	ft_printf("%s", s);
	if (!list || !*list || !(*list)->next)
		return ;
	store[0] = *list;
	store[1] = store[0]->next;
	store[2] = store[1]->next;
	*list = store[1];
	(*list)->next = store[0];
	store[0]->next = store[2];
}
