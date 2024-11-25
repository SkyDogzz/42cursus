/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:11:48 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/20 23:25:19 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*create_and_add_elem(t_list **new_lst, void *content,
	void (*del)(void *))
{
	t_list	*new_elem;

	new_elem = ft_lstnew(content);
	if (!new_elem)
	{
		del(content);
		ft_lstclear(new_lst, del);
		return (NULL);
	}
	ft_lstadd_back(new_lst, new_elem);
	return (new_elem);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	void	*new_content;

	if (!lst || !f)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		if (!new_content)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		if (!create_and_add_elem(&new_lst, new_content, del))
			return (NULL);
		lst = lst->next;
	}
	return (new_lst);
}
