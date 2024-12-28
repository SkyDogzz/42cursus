/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 04:26:37 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/28 06:25:11 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	strcat_space(char *dest, const char *src)
{
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest++ = ' ';
	*dest = 0;
}

t_bool	args_valid(const char *args)
{
	while (*args)
	{
		if (!ft_isdigit(*args) && !ft_isspace(*args) && *args != '-')
			return (FALSE);
		args++;
	}
	return (TRUE);
}

void	push_bottom(t_stack *stack, int value)
{
	t_node	*new_nod;
	t_node	*current;

	new_nod = malloc(sizeof(t_node));
	if (!new_nod)
		exit(EXIT_FAILURE);
	new_nod->value = value;
	new_nod->next = NULL;
	if (stack->top == NULL)
		stack->top = new_nod;
	else
	{
		current = stack->top;
		while (current->next != NULL)
			current = current->next;
		current->next = new_nod;
	}
	stack->size++;
}

t_bool	get_args(t_stack *stack, const char *s)
{
	long	atol;

	atol = ft_atol(s);
	if (atol > INT_MAX || atol < INT_MIN)
		return (FALSE);
	push_bottom(stack, (int)atol);
	while (*s)
	{
		while (*s == '-')
			s++;
		while (ft_isdigit(*s))
			s++;
		while (ft_isspace(*s))
			s++;
		if (*s == 0)
			return (TRUE);
		atol = ft_atol(s);
		if (atol > INT_MAX || atol < INT_MIN)
			return (FALSE);
		push_bottom(stack, (int)atol);
	}
	return (TRUE);
}

t_stack	*parse_args(t_stack *stack, int argc, char *argv[])
{
	int		pos;
	int		size;
	char	*full;

	pos = 0;
	size = 0;
	while (++pos < argc)
		size += ft_strlen(argv[pos]) + 1;
	full = (char *)ft_calloc(size + 1, sizeof(char));
	pos = 0;
	while (++pos < argc)
		strcat_space(full, argv[pos]);
	if (!args_valid(full) || !get_args(stack, full))
	{
		free(full);
		free(stack);
		return (NULL);
	}
	free(full);
	return (stack);
}
