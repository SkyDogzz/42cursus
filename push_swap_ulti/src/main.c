/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:03:45 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/19 13:34:13 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(void)
{
	t_snode	*stack;

	stack = create_stack();

	if (is_empty_stack(stack))
		ft_printf("Stack is empty\n");
	else
		ft_printf("Stack contain element(s)\n");

	stack = push_stack(stack, 11);
		print_stack(stack);
	stack = push_stack(stack, 22);
		print_stack(stack);
	stack = push_stack(stack, 33);
		print_stack(stack);
	stack = push_stack(stack, 44);
		print_stack(stack);

	return EXIT_SUCCESS;
}
