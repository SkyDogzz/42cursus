/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:36:57 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/10 21:16:30 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	display_full(t_list *l1, t_list *l2)
{	
	int	*n1;
	int	*n2;

	while (l1 || l2)
	{
		n1 = NULL;
		if (l1)
		{
			n1 = l1->content;
			if (l1->content)
				l1 = l1->next;
			ft_printf("%-3d ", *n1);
		}
		else
			ft_printf("    ");
		if (l2)
		{
			n2 = l2->content;
			if (l2->content)
				l2 = l2->next;
			ft_printf("%3d", *n2);
		}
		ft_printf("\n");
	}
	ft_printf("-------\n");
}

int	main(int argc, char *argv[])
{
	t_list		*l1;
	t_list		*l2;
	t_wrapper	wrapper;

	if (argc != 2)
	{
		ft_dprintf(2, "Usage: %s {args}\n", argv[0]);
		return (EXIT_FAILURE);
	}
	l1 = parse_input(argv[1]);
	l2 = NULL;
	// display_full(l1, l2);
	wrapper.count = 0;
	// dumb_sort(&wrapper, &l1, &l2);
	// dumb_sort_2(&wrapper, &l1, &l2);
	dumb_sort_3(&wrapper, &l1, &l2);
	// display_full(l1, l2);
	free_list(l1);
	free_list(l2);
	ft_printf("%d instructions\n", wrapper.count);
	return (EXIT_SUCCESS);
}
