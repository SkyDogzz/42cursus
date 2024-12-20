/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:57:31 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/20 19:25:35 by tstephan         ###   ########.fr       */
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
	free_wrapper(wrapper);
	return (EXIT_SUCCESS);
}
