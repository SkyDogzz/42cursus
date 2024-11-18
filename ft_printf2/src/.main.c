/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:24:45 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/18 00:55:47 by skydogzz         ###   ########.fr       */
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

	printf("\n\n%d\n\n", (-1 & (1 << (sizeof(int) * 8 - 1))) != 0);

	ft_printf(" %.1d ", 0);
	ft_printf(" %.2d ", -1);
	a = ft_printf(" %.2d ", 1);
	ft_printf(" %.1d ", 9);
	ft_printf(" %.2d ", 10);
	ft_printf(" %.3d ", 11);
	ft_printf(" %.4d ", 15);
	ft_printf(" %.5d ", 16);
	ft_printf(" %.6d ", 17);
	ft_printf(" %.1d ", 99);
	ft_printf(" %.2d ", 100);
	ft_printf(" %.3d ", 101);
	ft_printf(" %.1d ", -9);
	ft_printf(" %.2d ", -10);
	ft_printf(" %.3d ", -11);
	ft_printf(" %.4d ", -14);
	ft_printf(" %.1d ", -15);
	ft_printf(" %.2d ", -16);
	ft_printf(" %.3d ", -99);
	ft_printf(" %.3d ", -100);
	ft_printf(" %.4d ", -101);
	ft_printf(" %.8d ", INT_MAX);
	ft_printf(" %.9d ", INT_MIN);
	ft_printf(" %.10d ", LONG_MAX);
	ft_printf(" %.11d ", LONG_MIN);
	ft_printf(" %.12d ", UINT_MAX);
	ft_printf(" %.13d ", ULONG_MAX);
	ft_printf(" %.14d ", 9223372036854775807LL);
	ft_printf(" %.8d %.9d %.10d %.11d %.12d %.13d %.14d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	printf("\n");
	printf(" %.1d ", 0);
	printf(" %.2d ", -1);
	b = printf(" %.2d ", 1);
	printf(" %.1d ", 9);
	printf(" %.2d ", 10);
	printf(" %.3d ", 11);
	printf(" %.4d ", 15);
	printf(" %.5d ", 16);
	printf(" %.6d ", 17);
	printf(" %.1d ", 99);
	printf(" %.2d ", 100);
	printf(" %.3d ", 101);
	printf(" %.1d ", -9);
	printf(" %.2d ", -10);
	printf(" %.3d ", -11);
	printf(" %.4d ", -14);
	printf(" %.1d ", -15);
	printf(" %.2d ", -16);
	printf(" %.3d ", -99);
	printf(" %.3d ", -100);
	printf(" %.4d ", -101);
	printf(" %.8d ", INT_MAX);
	printf(" %.9d ", INT_MIN);
	printf(" %.10d ", LONG_MAX);
	printf(" %.11d ", LONG_MIN);
	printf(" %.12d ", UINT_MAX);
	printf(" %.13d ", ULONG_MAX);
	printf(" %.14d ", 9223372036854775807LL);
	printf(" %.8d %.9d %.10d %.11d %.12d %.13d %.14d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	/*ft_printf(" %.1i ", 0);*/
	/*ft_printf(" %.2i ", -1);*/
	/*ft_printf(" %.2i ", 1);*/
	/*ft_printf(" %.1i ", 9);*/
	/*ft_printf(" %.2i ", 10);*/
	/*ft_printf(" %.3i ", 11);*/
	/*ft_printf(" %.4i ", 15);*/
	/*ft_printf(" %.5i ", 16);*/
	/*ft_printf(" %.6i ", 17);*/
	/*ft_printf(" %.1i ", 99);*/
	/*ft_printf(" %.2i ", 100);*/
	/*ft_printf(" %.3i ", 101);*/
	/*ft_printf(" %.1i ", -9);*/
	/*ft_printf(" %.2i ", -10);*/
	/*ft_printf(" %.3i ", -11);*/
	/*ft_printf(" %.4i ", -14);*/
	/*ft_printf(" %.1i ", -15);*/
	/*ft_printf(" %.2i ", -16);*/
	/*ft_printf(" %.3i ", -99);*/
	/*ft_printf(" %.3i ", -100);*/
	/*ft_printf(" %.4i ", -101);*/
	/*ft_printf(" %.8i ", INT_MAX);*/
	/*ft_printf(" %.9i ", INT_MIN);*/
	/*ft_printf(" %.10i ", LONG_MAX);*/
	/*ft_printf(" %.11i ", LONG_MIN);*/
	/*ft_printf(" %.12i ", UINT_MAX);*/
	/*ft_printf(" %.13i ", ULONG_MAX);*/
	/*ft_printf(" %.14i ", 9223372036854775807LL);*/
	/*ft_printf(" %.8i %.9i %.10i %.11i %.12i %.13i %.14i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);*/
	/**/
	/*ft_printf(" %.1u ", 0);*/
	/*ft_printf(" %.2u ", -1);*/
	/*ft_printf(" %.2u ", 1);*/
	/*ft_printf(" %.1u ", 9);*/
	/*ft_printf(" %.2u ", 10);*/
	/*ft_printf(" %.3u ", 11);*/
	/*ft_printf(" %.4u ", 15);*/
	/*ft_printf(" %.5u ", 16);*/
	/*ft_printf(" %.6u ", 17);*/
	/*ft_printf(" %.1u ", 99);*/
	/*ft_printf(" %.2u ", 100);*/
	/*ft_printf(" %.3u ", 101);*/
	/*ft_printf(" %.1u ", -9);*/
	/*ft_printf(" %.2u ", -10);*/
	/*ft_printf(" %.3u ", -11);*/
	/*ft_printf(" %.4u ", -14);*/
	/*ft_printf(" %.1u ", -15);*/
	/*ft_printf(" %.2u ", -16);*/
	/*ft_printf(" %.3u ", -99);*/
	/*ft_printf(" %.3u ", -100);*/
	/*ft_printf(" %.4u ", -101);*/
	/*ft_printf(" %.8u ", INT_MAX);*/
	/*ft_printf(" %.9u ", INT_MIN);*/
	/*ft_printf(" %.10u ", LONG_MAX);*/
	/*ft_printf(" %.11u ", LONG_MIN);*/
	/*ft_printf(" %.12u ", UINT_MAX);*/
	/*ft_printf(" %.13u ", ULONG_MAX);*/
	/*ft_printf(" %.14u ", 9223372036854775807LL);*/
	/*ft_printf(" %.8u %.9u %.10u %.11u %.12u %.13u %.14u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);*/
	/**/
	/*ft_printf(" %.1x ", 0);*/
	/*ft_printf(" %.2x ", -1);*/
	/*ft_printf(" %.2x ", 1);*/
	/*ft_printf(" %.1x ", 9);*/
	/*ft_printf(" %.2x ", 10);*/
	/*ft_printf(" %.3x ", 11);*/
	/*ft_printf(" %.4x ", 15);*/
	/*ft_printf(" %.5x ", 16);*/
	/*ft_printf(" %.6x ", 17);*/
	/*ft_printf(" %.1x ", 99);*/
	/*ft_printf(" %.2x ", 100);*/
	/*ft_printf(" %.3x ", 101);*/
	/*ft_printf(" %.1x ", -9);*/
	/*ft_printf(" %.2x ", -10);*/
	/*ft_printf(" %.3x ", -11);*/
	/*ft_printf(" %.4x ", -14);*/
	/*ft_printf(" %.1x ", -15);*/
	/*ft_printf(" %.2x ", -16);*/
	/*ft_printf(" %.3x ", -99);*/
	/*ft_printf(" %.3x ", -100);*/
	/*ft_printf(" %.4x ", -101);*/
	/*ft_printf(" %.8x ", INT_MAX);*/
	/*ft_printf(" %.9x ", INT_MIN);*/
	/*ft_printf(" %.10x ", LONG_MAX);*/
	/*ft_printf(" %.11x ", LONG_MIN);*/
	/*ft_printf(" %.12x ", UINT_MAX);*/
	/*ft_printf(" %.13x ", ULONG_MAX);*/
	/*ft_printf(" %.14x ", 9223372036854775807LL);*/
	/*ft_printf(" %.8x %.9x %.10x %.11x %.12x %.13x %.14x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);*/
	/**/
	/*ft_printf(" %.1X ", 0);*/
	/*ft_printf(" %.2X ", -1);*/
	/*ft_printf(" %.2X ", 1);*/
	/*ft_printf(" %.1X ", 9);*/
	/*ft_printf(" %.2X ", 10);*/
	/*ft_printf(" %.3X ", 11);*/
	/*ft_printf(" %.4X ", 15);*/
	/*ft_printf(" %.5X ", 16);*/
	/*ft_printf(" %.6X ", 17);*/
	/*ft_printf(" %.1X ", 99);*/
	/*ft_printf(" %.2X ", 100);*/
	/*ft_printf(" %.3X ", 101);*/
	/*ft_printf(" %.1X ", -9);*/
	/*ft_printf(" %.2X ", -10);*/
	/*ft_printf(" %.3X ", -11);*/
	/*ft_printf(" %.4X ", -14);*/
	/*ft_printf(" %.1X ", -15);*/
	/*ft_printf(" %.2X ", -16);*/
	/*ft_printf(" %.3X ", -99);*/
	/*ft_printf(" %.3X ", -100);*/
	/*ft_printf(" %.4X ", -101);*/
	/*ft_printf(" %.8X ", INT_MAX);*/
	/*ft_printf(" %.9X ", INT_MIN);*/
	/*ft_printf(" %.10X ", LONG_MAX);*/
	/*ft_printf(" %.11X ", LONG_MIN);*/
	/*ft_printf(" %.12X ", UINT_MAX);*/
	/*ft_printf(" %.13X ", ULONG_MAX);*/
	/*ft_printf(" %.14X ", 9223372036854775807LL);*/
	/*ft_printf(" %.8X %.9X %.10X %.11X %.12X %.13X %.14X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);*/

	printf("\n\n%d, %d\n\n", a, b);
	
	return EXIT_SUCCESS;
}
