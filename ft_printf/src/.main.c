/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:24:45 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/18 16:47:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;

	int a, b;

	ft_printf(" %.1x ", 0);
	ft_printf(" %.2x ", -1);
	ft_printf(" %.2x ", 1);
	ft_printf(" %.1x ", 9);
	ft_printf(" %.2x ", 10);
	ft_printf(" %.3x ", 11);
	ft_printf(" %.4x ", 15);
	ft_printf(" %.5x ", 16);
	ft_printf(" %.6x ", 17);
	ft_printf(" %.1x ", 99);

	printf("\n");

	printf(" %.1x ", 0);
	printf(" %.2x ", -1);
	printf(" %.2x ", 1);
	printf(" %.1x ", 9);
	printf(" %.2x ", 10);
	printf(" %.3x ", 11);
	printf(" %.4x ", 15);
	printf(" %.5x ", 16);
	printf(" %.6x ", 17);
	printf(" %.1x ", 99);
		printf("\n\n%d, %d\n\n", a, b);
	
	return EXIT_SUCCESS;
}
