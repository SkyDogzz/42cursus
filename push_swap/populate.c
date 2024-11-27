/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:14:55 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/27 15:19:00 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_canatoi(const char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\f' || *str == '\v')
		str++;
	if (*str == '+' || *str == '-')
		str++;
	return (*str >= '0' && *str <= '9');
}

t_bool	ft_onlyint(int argc, char *argv[])
{
	int	pos;

	pos = 1;
	while (pos < argc)
		if (!ft_canatoi(argv[pos++]))
			return (FALSE);
	return (TRUE);
}

void	ft_populate(t_number *pile, char *argv[], size_t n)
{
	size_t	pos;
	size_t	pos2;

	pos = 1;
	while (pos < n)
	{
		pos2 = 0;
		pile[pos - 1].number = ft_atoi(argv[pos]);
		pile[pos - 1].indice = pos;
		pos++;
	}
}

void	ft_check_populate(t_number *pile_a, int argc, char **argv)
{
	if (!ft_onlyint(argc, argv))
	{
		ft_dprintf(2, "Not only int in args!\n");
		exit(0);
	}
	ft_populate(pile_a, argv, argc);
	ft_displaypile(pile_a, argc - 1);
}
