/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:58:00 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/22 02:08:31 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../include/stack.h"
# include "../include/instruction.h"
# include "../include/parse.h"

typedef struct s_wrapper
{
	t_stack	*main;
	t_stack	*temp;
	t_inst	*inst;
}	t_wrapper;

t_wrapper	*create_wrapper(void);
void		free_wrapper(t_wrapper *wrapper);

void		execsa(t_wrapper *wrapper);
void		execsb(t_wrapper *wrapper);
void		execss(t_wrapper *wrapper);
void		execpa(t_wrapper *wrapper);
void		execpb(t_wrapper *wrapper);
void		execra(t_wrapper *wrapper);
void		execrb(t_wrapper *wrapper);
void		execrr(t_wrapper *wrapper);
void		execrra(t_wrapper *wrapper);
void		execrrb(t_wrapper *wrapper);

void		sort_stack(t_wrapper *wrapper);

#endif
