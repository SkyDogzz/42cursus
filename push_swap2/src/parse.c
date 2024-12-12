/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 04:26:37 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/12 05:17:48 by skydogzz         ###   ########.fr       */
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
	free(full);
	return (stack);
}
