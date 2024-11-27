/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:40:15 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/27 15:18:23 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_number	*pile_a;

	pile_a = (t_number *)malloc(sizeof(t_number) * (argc - 1));
	if (argc < 2)
	{
		ft_dprintf(2, "Not args\n");
		exit(0);
	}
	ft_check_populate(pile_a, argc, argv);
	return (EXIT_SUCCESS);
}
