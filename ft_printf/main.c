/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:37:03 by marvin            #+#    #+#             */
/*   Updated: 2024/11/10 16:06:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	ft_printf("Hello world!\n");
	ft_printf("H#ello world!\n");
	ft_printf("H% +ello world!\n");
	return (EXIT_SUCCESS);
}
