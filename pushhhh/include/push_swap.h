/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:58:00 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/20 20:13:48 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../include/stack.h"
# include "../include/instruction.h"

typedef struct s_wrapper
{
	t_stack	*main;
	t_stack	*temp;
	t_inst	*inst;
}	t_wrapper;

t_wrapper	*create_wrapper(void);
void		free_wrapper(t_wrapper *wrapper);

#endif
