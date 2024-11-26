/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:12:54 by marvin            #+#    #+#             */
/*   Updated: 2024/11/26 17:10:14 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_list	*ft_lstadd_back(t_list **lst, t_list *newl)
{
	t_list	*l;

	if (!lst || !newl)
		return (NULL);
	if (*lst == NULL)
	{
		*lst = newl;
		return (*lst);
	}
	l = *lst;
	while (l->next)
		l = l->next;
	l->next = newl;
	return (*lst);
}
