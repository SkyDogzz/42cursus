/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:37:37 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/11 18:21:17 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"

typedef struct s_wrapper
{
	t_list	*l1;
	t_list	*l2;
}	t_wrapper;

char	*get_to_next(char *args);
void	print(void *content);
void	print_tlist(t_list *list);
t_list	*parse_input(char *args);
void	free_list(t_list *list);
void	revrotate(t_list **list, const char *s);
void	rotate(t_list **list, const char *s);
void	push(t_list **l1, t_list **l2, const char *s);
void	swap(t_list **list, const char *s);
void	free_wrapper(t_wrapper *wrapper);
void	dumb_sort(t_wrapper *wrapper);
void	dumb_sort2(t_wrapper *wrapper);
void	dumb_sort3(t_wrapper *wrapper);
int		get_min(int a, int b);
void	better_algo(t_wrapper *wrapper);

#endif
