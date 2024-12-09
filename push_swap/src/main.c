/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:36:57 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/09 17:07:33 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	display_full(t_list *l1, t_list *l2)
{
	int	*v1;
	int	*v2;

	while ((l1 && l1->next) || (l2 && l2->next))
	{
		v1 = NULL;
		v2 = NULL;
		if (l1 && l1->content)
			v1 = l1->content;
		if (l2 && l2->content)
			v2 = l2->content;
		if (v1 && v2)
			ft_printf("%d %d\n", *v1, *v2);
		else if (v1 && !v2)
			ft_printf("%d\n", *v1);
		else if (!v1 && v2)
			ft_printf("  %d\n", *v2);
		l1 = l1->next;
	}
}

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
	display_full(l1, l2);
	free_list(l1);
	free_list(l2);
	return (EXIT_SUCCESS);
}
