/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:33:28 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/30 14:33:31 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	args_valid(const char *args)
{
	while (*args)
	{
		if (!ft_isdigit(*args) && !ft_isspace(*args) && *args != '-'
			&& *args != '+')
			return (FALSE);
		args++;
	}
	return (TRUE);
}

t_bool	repeat(t_stack *stack)
{
	t_node	*cursor;
	t_node	*act;

	cursor = stack->top;
	while (cursor)
	{
		act = cursor->next;
		while (act)
		{
			if (cursor->value == act->value)
				return (TRUE);
			act = act->next;
		}
		cursor = cursor->next;
	}
	return (FALSE);
}
