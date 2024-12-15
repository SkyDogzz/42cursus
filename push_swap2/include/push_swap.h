/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 03:02:47 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/15 19:16:50 by skydogzz         ###   ########.fr       */
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

typedef struct s_inode
{
	char			*value;
	struct s_inode	*next;
}	t_inode;

typedef struct s_inst
{
	t_inode	*top;
	size_t	size;
}	t_inst;


typedef struct s_cheap
{
	int	value;
	int	insert_pos;
	int	cost_s1;
	int	cost_s2;
	int	total_cost;
}	t_cheap;

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
void	sort_stack(t_inst *inst, t_stack *stack, t_stack *temp);

// instructions
void	optimize_instructions(t_inst *inst);
void	print_instructions(t_inst *inst);
void	add_instruction(t_inst *inst, const char *ins);

// push_swap utils
void	execpa(t_inst *inst, t_stack *stack, int value);
void	execpb(t_inst *inst, t_stack *stack, int value);
void	execra(t_inst *inst, t_stack *stack);
void	execrb(t_inst *inst, t_stack *stack);
void	execrra(t_inst *inst, t_stack *stack);
void	execrrb(t_inst *inst, t_stack *stack);

void	exit_with_error(const char *s);

void	get_on_top(t_inst *inst, t_stack *stack, int value);
void sort_stack_with_chunks(t_inst *inst, t_stack *stack, t_stack *temp, int number_of_chunks);
int	index_of(t_stack *stack, int value);
	
#endif
