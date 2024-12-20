/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:57:31 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/20 20:32:56 by tstephan         ###   ########.fr       */
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
	if (!parse_arg(wrapper->main, argc, argv) || !check_stack(wrapper->main))
	{
		ft_dprintf(2, "Args not correct\n");
		free_wrapper(wrapper);
		exit(EXIT_FAILURE);
	}
	print_stack(wrapper->main);
	free_wrapper(wrapper);
	return (EXIT_SUCCESS);
}
