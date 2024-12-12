/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 03:01:56 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/12 04:21:39 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(void)
{
	t_stack	*stack;

	stack = init_stack();
	print_stack(stack);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
