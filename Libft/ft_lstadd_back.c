/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:12:54 by marvin            #+#    #+#             */
/*   Updated: 2024/11/14 00:19:28 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_list	*ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l;

	if (!lst || !new)
		return (NULL);
	if (*lst == NULL)
	{
		*lst = new;
		return (*lst);
	}
	l = *lst;
	while (l->next)
		l = l->next;
	l->next = new;
	return (*lst);
}
