/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:24:45 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/18 11:56:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <limits.h>

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;

	int a, b;

	ft_printf(" %.1u ", 0);
	ft_printf(" %.2u ", -1);
	ft_printf(" %.2u ", 1);
	ft_printf(" %.1u ", 9);
	ft_printf(" %.2u ", 10);
	ft_printf(" %.3u ", 11);
	ft_printf(" %.4u ", 15);
	ft_printf(" %.5u ", 16);
	ft_printf(" %.6u ", 17);
	ft_printf(" %.1u ", 99);
	ft_printf(" %.2u ", 100);
	ft_printf(" %.3u ", 101);
	ft_printf(" %.1u ", -9);
	ft_printf(" %.2u ", -10);
	ft_printf(" %.3u ", -11);
	ft_printf(" %.4u ", -14);
	ft_printf(" %.1u ", -15);
	ft_printf(" %.2u ", -16);
	ft_printf(" %.3u ", -99);
	ft_printf(" %.3u ", -100);
	ft_printf(" %.4u ", -101);
	printf("\n");
	printf(" %.1u ", 0);
	printf(" %.2u ", -1);
	printf(" %.2u ", 1);
	printf(" %.1u ", 9);
	printf(" %.2u ", 10);
	printf(" %.3u ", 11);
	printf(" %.4u ", 15);
	printf(" %.5u ", 16);
	printf(" %.6u ", 17);
	printf(" %.1u ", 99);
	printf(" %.2u ", 100);
	printf(" %.3u ", 101);
	printf(" %.1u ", -9);
	printf(" %.2u ", -10);
	printf(" %.3u ", -11);
	printf(" %.4u ", -14);
	printf(" %.1u ", -15);
	printf(" %.2u ", -16);
	printf(" %.3u ", -99);
	printf(" %.3u ", -100);
	printf(" %.4u ", -101);
	
	printf("\n\n%d, %d\n\n", a, b);
	
	return EXIT_SUCCESS;
}
