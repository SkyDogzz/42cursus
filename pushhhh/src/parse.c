/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:22:19 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/20 20:32:53 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	parse_arg(t_stack *stack, int argc, char *argv[])
{
	int pos;

	pos = 1;
	while (pos < argc)
	{
		push_stack(stack, create_node(ft_atoi(argv[pos])));
		pos++;
	}
	return (TRUE);
}

t_bool	check_stack(t_stack *stack)
{
	// TODO
	return (TRUE);
}
