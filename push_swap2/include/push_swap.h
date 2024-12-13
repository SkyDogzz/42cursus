/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 03:02:47 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/13 01:34:18 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	size_t	size;
}	t_stack;

typedef	struct s_instruction
{
	t_list	*top;
	size_t	size;
}	t_instruction;

// stack related
t_stack	*init_stack(void);
t_node	*new_node(int value);
void	free_stack(t_stack *stack);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	print_stack(t_stack *stack);
int		get_value(t_stack *stack, int index);

// parse related
t_stack	*parse_args(t_stack *stack, int argc, char *argv[]);

// sort stack
void	sort_stack(t_stack *stack, t_stack *temp);

// instructions
void optimize_instructions(void);
void print_instructions(void);
void add_instruction(const char *ins);

// push_swap utils
void	execpa(t_stack *stack, int value);
void	execpb(t_stack *stack, int value);
void	execra(t_stack *stack);
void	execrb(t_stack *stack);
void	execrra(t_stack *stack);
void	execrrb(t_stack *stack);

#endif
