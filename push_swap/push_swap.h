/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:38:14 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/27 15:16:44 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/include/libft.h"
# include "libft/include/ft_printf.h"

typedef struct s_number
{
	int				number;
	unsigned int	indice;
}	t_number;

void	ft_check_populate(t_number *numbers, int argc, char *argv[]);
void	ft_displaypile(t_number *pile, size_t n);
void	ft_displaypileindice(t_number *pile, size_t n);
void	quicksort(int *arr, int low, int high);

#endif
