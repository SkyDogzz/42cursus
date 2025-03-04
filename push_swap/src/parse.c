/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:42:33 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/11 18:47:00 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*get_to_next(char *args)
{
	while (ft_isdigit(*args))
		args++;
	while (ft_isspace(*args))
		args++;
	if (*args == '\0')
		return (NULL);
	return (args);
}

void	print(void *content)
{
	int	*nbr;

	nbr = (int *)content;
	ft_printf("%d ", *nbr);
}

void	print_tlist(t_list *list)
{
	ft_lstiter(list, &print);
	ft_printf("\n");
}

t_list	*parse_input(char *args)
{
	t_list	*parsed;
	int		*nbr;

	parsed = NULL;
	while (args)
	{
		nbr = malloc(sizeof(int));
		if (!nbr)
		{
			ft_dprintf(2, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		*nbr = ft_atoi(args);
		ft_lstadd_back(&parsed, ft_lstnew(nbr));
		args = get_to_next(args);
	}
	return (parsed);
}
