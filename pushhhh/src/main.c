/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:57:31 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/20 20:14:57 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_wrapper	*wrapper;

	wrapper = create_wrapper();
	print_stack(wrapper->main);
	push_stack(wrapper->main, create_node(10));
	push_stack(wrapper->main, create_node(20));
	push_stack(wrapper->main, create_node(30));
	push_stack(wrapper->main, create_node(40));
	print_stack(wrapper->main);
	rotate_stack(wrapper->main);
	print_stack(wrapper->main);
	rotate_stack(wrapper->main);
	print_stack(wrapper->main);
	rotate_stack(wrapper->main);
	print_stack(wrapper->main);
	rotate_stack(wrapper->main);
	print_stack(wrapper->main);
	rev_rotate_stack(wrapper->main);
	print_stack(wrapper->main);
	rev_rotate_stack(wrapper->main);
	print_stack(wrapper->main);
	rev_rotate_stack(wrapper->main);
	print_stack(wrapper->main);
	rev_rotate_stack(wrapper->main);
	print_stack(wrapper->main);
	swap(wrapper->main);
	print_stack(wrapper->main);
	ft_printf("Stack size = %d\n", size_stack(wrapper->main));
	ft_printf("%d popped of the stack\n", pop_stack(wrapper->main));
	ft_printf("%d popped of the stack\n", pop_stack(wrapper->main));
	ft_printf("%d popped of the stack\n", pop_stack(wrapper->main));
	ft_printf("%d popped of the stack\n", pop_stack(wrapper->main));
	print_stack(wrapper->main);
	ft_printf("Stack size = %d\n", size_stack(wrapper->main));
	add_inst(wrapper->inst, "first inst");
	add_inst(wrapper->inst, "second inst");
	add_inst(wrapper->inst, "third inst");
	print_inst(wrapper->inst);
	free_wrapper(wrapper);
	return (EXIT_SUCCESS);
}
