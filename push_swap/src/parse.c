/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:42:33 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/10 18:49:30 by tstephan         ###   ########.fr       */
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
		ft_lstadd_front(&parsed, ft_lstnew(nbr));
		args = get_to_next(args);
	}
	return (parsed);
}

void	free_list(t_list *list)
{
	t_list	*temp;

	while (list && list->content)
	{
		temp = list;
		free(list->content);
		list = list->next;
		free(temp);
	}
}
