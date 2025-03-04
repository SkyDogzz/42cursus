/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:36:57 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/11 20:10:00 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	display_full(t_wrapper wrapper)
{	
	int	*n1;
	int	*n2;

	while (wrapper.l1 || wrapper.l2)
	{
		n1 = NULL;
		if (wrapper.l1)
		{
			n1 = wrapper.l1->content;
			if (wrapper.l1->content)
				wrapper.l1 = wrapper.l1->next;
			ft_printf("%-3d ", *n1);
		}
		else
			ft_printf("    ");
		if (wrapper.l2)
		{
			n2 = wrapper.l2->content;
			if (wrapper.l2->content)
				wrapper.l2 = wrapper.l2->next;
			ft_printf("%3d", *n2);
		}
		ft_printf("\n");
	}
	ft_printf("-------\n");
}

int	main(int argc, char *argv[])
{
	t_wrapper	wrapper;

	if (argc < 2)
	{
		ft_dprintf(2, "Usage: %s {args}\n", argv[0]);
		return (EXIT_FAILURE);
	}
	wrapper.l1 = parse_input(argv[1]);
	wrapper.l2 = NULL;
	display_full(wrapper);
	// dumb_sort(&wrapper);
	// dumb_sort3(&wrapper);
	better_algo(&wrapper);
	display_full(wrapper);
	free_wrapper(&wrapper);
	return (EXIT_SUCCESS);
}
