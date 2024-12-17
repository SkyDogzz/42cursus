/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:41:45 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/08 16:55:26 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_bool	inlist(t_list *keys, int keycode)
{
	while (keys)
	{
		if (*(int *)keys->content == keycode)
			return (TRUE);
		keys = keys->next;
	}
	return (FALSE);
}

void	add_key(t_list **keys, int keycode)
{
	t_list	*new;
	t_list	*temp;

	temp = *keys;
	while (temp)
	{
		if (*(int *)temp->content == keycode)
			return ;
		temp = temp->next;
	}
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->content = malloc(sizeof(int));
	if (!new->content)
	{
		free(new);
		return ;
	}
	*(int *)new->content = keycode;
	new->next = *keys;
	*keys = new;
}

void	remove_key(t_list **keys, int keycode)
{
	t_list	*temp;
	t_list	*prev;

	temp = *keys;
	prev = NULL;
	while (temp)
	{
		if (*(int *)temp->content == keycode)
		{
			if (prev)
				prev->next = temp->next;
			else
				*keys = temp->next;
			free(temp->content);
			free(temp);
			return ;
		}
		prev = temp;
		temp = temp->next;
	}
}

void	free_keys(t_list **keys)
{
	t_list	*temp;

	while (*keys)
	{
		temp = *keys;
		*keys = (*keys)->next;
		free(temp->content);
		free(temp);
	}
}
