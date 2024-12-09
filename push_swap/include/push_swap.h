/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:37:37 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/09 16:44:20 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"

char	*get_to_next(char *args);
void	print(void *content);
void	print_tlist(t_list *list);
t_list	*parse_input(char *args);
void	free_list(t_list *list);
void	revrotate(t_list **list);
void	rotate(t_list **list);
void	push(t_list **l1, t_list **l2);
void	swap(t_list **list);

#endif
