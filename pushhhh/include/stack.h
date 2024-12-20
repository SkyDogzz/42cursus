/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:00:06 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/20 20:14:01 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stddef.h>
# include "../libft/include/libft.h"

typedef struct s_snode
{
	int				value;
	struct s_snode	*next;
}	t_snode;

typedef struct s_stack
{
	t_snode	*top;
	size_t	size;
}	t_stack;

t_stack	*create_stack(void);
t_bool	is_empty_stack(t_stack *stack);
int		size_stack(t_stack	*stack);
t_snode	*create_node(int value);
t_bool	push_stack(t_stack *stack, t_snode *node);
int		pop_stack(t_stack	*stack);
void	print_stack(t_stack	*stack);
void	free_stack(t_stack *stack);
t_snode	*get_node(t_stack *stack, int index);

void	rotate_stack(t_stack *stack);
void	rev_rotate_stack(t_stack *stack);
void	swap(t_stack *stack);

#endif
