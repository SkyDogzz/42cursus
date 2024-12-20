/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:19:14 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/20 19:50:15 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_wrapper	*create_wrapper(void)
{
	t_wrapper	*wrapper;

	wrapper = (t_wrapper *)malloc(sizeof(t_wrapper));
	if (!wrapper)
	{
		ft_dprintf(2, "Failed to malloc wrapper\n");
		return (NULL);
	}
	wrapper->main = create_stack();
	wrapper->temp = create_stack();
	wrapper->inst = create_inst();
	return (wrapper);
}

void	free_wrapper(t_wrapper *wrapper)
{
	free_stack(wrapper->main);
	free_stack(wrapper->temp);
	free_inst(wrapper->inst);
	free(wrapper);
}
