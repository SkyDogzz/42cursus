/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:13:41 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/19 13:49:43 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_snode	*create_stack(void)
{
	return (NULL);
}

int		is_empty_stack(t_snode *top)
{
	if (!top)
		return (1);
	return (0);
}

t_snode	*push_stack(t_snode *top, int value)
{
	t_snode	*new_top;

	new_top = (t_snode *)malloc(sizeof(t_snode));
	if (!new_top)
		return (NULL);
	new_top->next = top;
	new_top->value = value;
	return (new_top);
}

int	pop_stack(t_snode *top)
{
	int		popped;
	t_snode	*old_top;
	
	popped = top->value;
	old_top = top;
	top = top->next;
	free(old_top);
	return (popped);
}

void	print_stack(t_snode *top)
{
	while (is_empty_stack(top))
	{
		ft_printf("%d ", top->value);
		top = top->next;
	}
	ft_printf("%\n");
}
