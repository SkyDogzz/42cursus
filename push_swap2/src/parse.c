/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 04:26:37 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/13 07:51:49 by skydogzz         ###   ########.fr       */
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
		if (!ft_isdigit(*args) && !ft_isspace(*args))
			return (FALSE);
		args++;
	}
	return (TRUE);
}

void push_bottom(t_stack *stack, int value) {
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node) {
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->next = NULL;

    if (stack->top == NULL) {
        // If the stack is empty, set top to the new node
        stack->top = new_node;
    } else {
        // Traverse to the last node
        t_node *current = stack->top;
        while (current->next != NULL) {
            current = current->next;
        }
        // Link the new node at the end
        current->next = new_node;
    }

    stack->size++;
}

void	get_args(t_stack *stack, const char *s)
{
	push_bottom(stack, ft_atoi(s));
	while (*s)
	{
		while (ft_isdigit(*s))
			s++;
		while (ft_isspace(*s))
			s++;
		if (*s == 0)
			return ;
		push_bottom(stack, ft_atoi(s));
	}
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
	if (!args_valid(full))
		return (NULL);
	get_args(stack, full);
	free(full);
	return (stack);
}
