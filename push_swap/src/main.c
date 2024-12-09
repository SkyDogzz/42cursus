/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:36:57 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/09 16:42:22 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	revrotate(t_list **list)
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
}

void	rotate(t_list **list)
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
}

void	push(t_list **l1, t_list **l2)
{
	t_list	*act;
	if (!l1 || !*l1)
		return ;
	act = *l1;
	while (act->next->next)
		act = act->next;
	ft_lstadd_front(l2, ft_lstnew(act->next->content));
	act->next = NULL;
}

void	swap(t_list **list)
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
}

int	main(int argc, char *argv[])
{
	t_list	*l1;
	t_list	*l2;

	if (argc != 2)
	{
		ft_dprintf(2, "Usage: %s {args}\n", argv[0]);
		return (EXIT_FAILURE);
	}
	l1 = parse_input(argv[1]);
	l2 = NULL;
	print_tlist(l1);
	print_tlist(l2);
	swap(&l1);
	print_tlist(l1);
	print_tlist(l2);
	rotate(&l1);
	print_tlist(l1);
	print_tlist(l2);
	revrotate(&l1);
	print_tlist(l1);
	print_tlist(l2);
	free_list(l1);
	free_list(l2);
	return (EXIT_SUCCESS);
}
