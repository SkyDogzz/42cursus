/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:07:29 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/19 13:37:03 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_snode
{
	int				value;
	struct s_snode	*next;
}	t_snode;

t_snode	*create_stack(void);
int		is_empty_stack(t_snode *top);
t_snode	*push_stack(t_snode *top, int value);
int		pop_stack(t_snode *top);
void	print_stack(t_snode *top);

#endif
