/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:57:31 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/21 22:25:59 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_wrapper	*wrapper;

	if (argc == 1)
	{
		ft_dprintf(2, "Usage: %s {ARGS}\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	wrapper = create_wrapper();
	if (!parse_arg(wrapper->main, argc, argv) || !check_stack(wrapper->main,
			argc, argv))
	{
		ft_dprintf(2, "Args not correct\n");
		free_wrapper(wrapper);
		exit(EXIT_FAILURE);
	}
	print_stack(wrapper->main);
	sort_stack(wrapper);
	print_stack(wrapper->main);
	print_inst(wrapper->inst);
	free_wrapper(wrapper);
	return (EXIT_SUCCESS);
}
