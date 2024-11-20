/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_carac.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:23:59 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/20 18:50:23 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_initcaracs(struct s_carac *caracs)
{
	caracs->size = 0;
	caracs->pad = 0;
	caracs->padleft = 0;
}
