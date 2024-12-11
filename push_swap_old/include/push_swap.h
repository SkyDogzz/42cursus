/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:37:37 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/11 15:41:58 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"

typedef struct s_wrapper
{
	int	count;
	t_list	*l1;
	t_list	*l2;
}	t_wrapper;

char	*get_to_next(char *args);
void	print(void *content);
void	print_tlist(t_list *list);
t_list	*parse_input(char *args);
void	free_list(t_list *list);
void	revrotate(t_wrapper *wrapper, int l);
void	rotate(t_wrapper *wrapper, int l);
void	push(t_wrapper *wrapper, int orig);
void	swap(t_wrapper *wrapper, int l);
void	display_full(t_list *l1, t_list *l2);
int		find_max_index(t_wrapper *wrapper, int l);
int		find_min_index(t_wrapper *wrapper, int l);
void	free_wrapper(t_wrapper wrapper);
void	dumb_sort(t_wrapper *wrapper);
void	dumb_sort_2(t_wrapper *wrapper);
void	dumb_sort_3(t_wrapper *wrapper);
void	chunky_sort(t_wrapper *wrapper, t_list **l1, t_list **l2);

#endif
