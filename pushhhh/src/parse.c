/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:22:19 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/21 14:18:45 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*get_next_nbr(char *s)
{
	while (*s == '-' || ft_isdigit(*s))
		s++;
	while (*s == ' ')
		s++;
	if (*s == 0)
		return (NULL);
	return (s);
}

t_bool	parse_arg(t_stack *stack, int argc, char *argv[])
{
	char	*act;
	int		pos;

	pos = 1;
	while (pos < argc)
	{
		act = argv[pos];
		while (act)
		{
			push_stack(stack, create_node(ft_atoi(act)));
			act = get_next_nbr(act);
		}
		pos++;
	}
	return (TRUE);
}

t_bool	contain_forbidden(int argc, char *argv[])
{
	int	pos;

	pos = 1;
	while (pos < argc)
	{
		while (*argv[pos])
		{
			if (!ft_isdigit(*argv[pos]) && *argv[pos] != ' '
				&& *argv[pos] != '-')
				return (TRUE);
			argv[pos]++;
		}
		pos++;
	}
	return (FALSE);
}

t_bool	check_stack(t_stack *stack, int argc, char *argv[])
{
	t_snode	*cursor;
	t_snode	*act;

	cursor = stack->top;
	while (cursor)
	{
		act = cursor->next;
		while (act)
		{
			if (cursor->value == act->value)
				return (FALSE);
			act = act->next;
		}
		cursor = cursor->next;
	}
	return (!contain_forbidden(argc, argv));
}
