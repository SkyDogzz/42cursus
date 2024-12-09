/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:36:57 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/09 16:45:23 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*l1;
	t_list	*l2;

	if (argc != 2)
	{
		ft_dprintf(2, "Usage: %s {args}\n", argv[0]);
		return (EXIT_FAILURE);
	}
	l1 = parse_input(argv[1]);
	l2 = NULL;
	print_tlist(l1);
	print_tlist(l2);
	swap(&l1);
	print_tlist(l1);
	print_tlist(l2);
	rotate(&l1);
	print_tlist(l1);
	print_tlist(l2);
	revrotate(&l1);
	print_tlist(l1);
	print_tlist(l2);
	free_list(l1);
	free_list(l2);
	return (EXIT_SUCCESS);
}
