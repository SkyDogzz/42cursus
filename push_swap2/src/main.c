/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 03:01:56 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/13 02:42:54 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exit_with_error(const char *error)
{
	ft_dprintf(2, "%s", error);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack;
	t_stack	*temp;
	t_inst	*inst;

	if (argc == 1)
		exit_with_error("No args\n");
	stack = init_stack();
	temp = init_stack();
	stack = parse_args(stack, argc, argv);
	// print_stack(stack);
	sort_stack(inst, stack, temp);
	print_stack(stack);
	optimize_instructions();
	print_instructions();
	free_stack(stack);
	free_stack(temp);
	return (EXIT_SUCCESS);
}
