/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:24:45 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/17 18:10:15 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;

	ft_printf(" %2p ", -1);
	ft_printf(" %-2p ", -1);
	ft_printf(" %-2p ", 1);
	ft_printf(" %-2p ", 15);
	ft_printf(" %-3p ", 16);
	ft_printf(" %-4p ", 17);
	ft_printf(" %-9p %-10p ", LONG_MIN, LONG_MAX);
	ft_printf(" %-11p %-12p ", INT_MIN, INT_MAX);
	ft_printf(" %-13p %-14p ", ULONG_MAX, -ULONG_MAX);
	ft_printf(" %-1p %-2p ", 0, 0);
	printf("\n %2p ", -1);
	printf(" %-2p ", -1);
	printf(" %-2p ", 1);
	printf(" %-2p ", 15);
	printf(" %-3p ", 16);
	printf(" %-4p ", 17);
	printf(" %-9p %-10p ", LONG_MIN, LONG_MAX);
	printf(" %-11p %-12p ", INT_MIN, INT_MAX);
	printf(" %-13p %-14p ", ULONG_MAX, -ULONG_MAX);
	printf(" %-1p %-2p \n", 0, 0);

	ft_printf("\n %-1d ", 0);
	ft_printf(" %-2d ", -1);
	ft_printf(" %-3d ", 1);
	ft_printf(" %-4d ", 9);
	ft_printf(" %-1d ", 10);
	ft_printf(" %-2d ", 11);
	ft_printf(" %-3d ", 15);
	ft_printf(" %-4d ", 16);
	ft_printf(" %-5d ", 17);
	ft_printf(" %-1d ", 99);
	ft_printf(" %-2d ", 100);
	ft_printf(" %-3d ", 101);
	ft_printf(" %-1d ", -9);
	ft_printf(" %-2d ", -10);
	ft_printf(" %-3d ", -11);
	ft_printf(" %-4d ", -14);
	ft_printf(" %-5d ", -15);
	ft_printf(" %-6d ", -16);
	ft_printf(" %-1d ", -99);
	ft_printf(" %-2d ", -100);
	ft_printf(" %-3d ", -101);
	ft_printf(" %-9d ", INT_MAX);
	ft_printf(" %-10d ", INT_MIN);
	ft_printf(" %-11d ", LONG_MAX);
	ft_printf(" %-12d ", LONG_MIN);
	ft_printf(" %-13d ", UINT_MAX);
	ft_printf(" %-14d ", ULONG_MAX);
	ft_printf(" %-15d ", 9223372036854775807LL);
	ft_printf(" %-9d %-10d %-11d %-12d %-13d %-14d %-15d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\n %-1d ", 0);
	printf(" %-2d ", -1);
	printf(" %-3d ", 1);
	printf(" %-4d ", 9);
	printf(" %-1d ", 10);
	printf(" %-2d ", 11);
	printf(" %-3d ", 15);
	printf(" %-4d ", 16);
	printf(" %-5d ", 17);
	printf(" %-1d ", 99);
	printf(" %-2d ", 100);
	printf(" %-3d ", 101);
	printf(" %-1d ", -9);
	printf(" %-2d ", -10);
	printf(" %-3d ", -11);
	printf(" %-4d ", -14);
	printf(" %-5d ", -15);
	printf(" %-6d ", -16);
	printf(" %-1d ", -99);
	printf(" %-2d ", -100);
	printf(" %-3d ", -101);
	printf(" %-9d ", INT_MAX);
	printf(" %-10d ", INT_MIN);
	printf(" %-11d ", LONG_MAX);
	printf(" %-12d ", LONG_MIN);
	printf(" %-13d ", UINT_MAX);
	printf(" %-14d ", ULONG_MAX);
	printf(" %-15d ", 9223372036854775807LL);
	printf(" %-9d %-10d %-11d %-12d %-13d %-14d %-15d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	ft_printf("\n %-1i ", 0);
	ft_printf(" %-2i ", -1);
	ft_printf(" %-3i ", 1);
	ft_printf(" %-4i ", 9);
	ft_printf(" %-1i ", 10);
	ft_printf(" %-2i ", 11);
	ft_printf(" %-3i ", 15);
	ft_printf(" %-4i ", 16);
	ft_printf(" %-5i ", 17);
	ft_printf(" %-1i ", 99);
	ft_printf(" %-2i ", 100);
	ft_printf(" %-3i ", 101);
	ft_printf(" %-1i ", -9);
	ft_printf(" %-2i ", -10);
	ft_printf(" %-3i ", -11);
	ft_printf(" %-4i ", -14);
	ft_printf(" %-5i ", -15);
	ft_printf(" %-6i ", -16);
	ft_printf(" %-1i ", -99);
	ft_printf(" %-2i ", -100);
	ft_printf(" %-3i ", -101);
	ft_printf(" %-9i ", INT_MAX);
	ft_printf(" %-10i ", INT_MIN);
	ft_printf(" %-11i ", LONG_MAX);
	ft_printf(" %-12i ", LONG_MIN);
	ft_printf(" %-13i ", UINT_MAX);
	ft_printf(" %-14i ", ULONG_MAX);
	ft_printf(" %-15i ", 9223372036854775807LL);
	ft_printf(" %-9i %-10i %-11i %-12i %-13i %-14i %-15i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\n %-1i ", 0);
	printf(" %-2i ", -1);
	printf(" %-3i ", 1);
	printf(" %-4i ", 9);
	printf(" %-1i ", 10);
	printf(" %-2i ", 11);
	printf(" %-3i ", 15);
	printf(" %-4i ", 16);
	printf(" %-5i ", 17);
	printf(" %-1i ", 99);
	printf(" %-2i ", 100);
	printf(" %-3i ", 101);
	printf(" %-1i ", -9);
	printf(" %-2i ", -10);
	printf(" %-3i ", -11);
	printf(" %-4i ", -14);
	printf(" %-5i ", -15);
	printf(" %-6i ", -16);
	printf(" %-1i ", -99);
	printf(" %-2i ", -100);
	printf(" %-3i ", -101);
	printf(" %-9i ", INT_MAX);
	printf(" %-10i ", INT_MIN);
	printf(" %-11i ", LONG_MAX);
	printf(" %-12i ", LONG_MIN);
	printf(" %-13i ", UINT_MAX);
	printf(" %-14i ", ULONG_MAX);
	printf(" %-15i ", 9223372036854775807LL);
	printf(" %-9i %-10i %-11i %-12i %-13i %-14i %-15i\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	ft_printf("\n %-1u ", 0);
	ft_printf("| %-2u |", -1);
	ft_printf("| %-3u |", 1);
	ft_printf(" %-4u ", 9);
	ft_printf(" %-1u ", 10);
	ft_printf(" %-2u ", 11);
	ft_printf(" %-3u ", 15);
	ft_printf(" %-4u ", 16);
	ft_printf(" %-5u ", 17);
	ft_printf(" %-1u ", 99);
	ft_printf(" %-2u ", 100);
	ft_printf(" %-3u ", 101);
	ft_printf(" %-1u ", -9);
	ft_printf(" %-2u ", -10);
	ft_printf(" %-3u ", -11);
	ft_printf(" %-4u ", -14);
	ft_printf(" %-5u ", -15);
	ft_printf(" %-6u ", -16);
	ft_printf(" %-1u ", -99);
	ft_printf(" %-2u ", -100);
	ft_printf(" %-3u ", -101);
	ft_printf(" %-9u ", INT_MAX);
	ft_printf(" %-10u ", INT_MIN);
	ft_printf(" %-11u ", LONG_MAX);
	ft_printf(" %-12u ", LONG_MIN);
	ft_printf(" %-13u ", UINT_MAX);
	ft_printf(" %-14u ", ULONG_MAX);
	ft_printf(" %-15u ", 9223372036854775807LL);
	ft_printf(" %-9u %-10u %-11u %-12u %-13u %-14u %-15u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\n %-1u ", 0);
	printf("| %-2u |", -1);
	printf("| %-3u |", 1);
	printf(" %-4u ", 9);
	printf(" %-1u ", 10);
	printf(" %-2u ", 11);
	printf(" %-3u ", 15);
	printf(" %-4u ", 16);
	printf(" %-5u ", 17);
	printf(" %-1u ", 99);
	printf(" %-2u ", 100);
	printf(" %-3u ", 101);
	printf(" %-1u ", -9);
	printf(" %-2u ", -10);
	printf(" %-3u ", -11);
	printf(" %-4u ", -14);
	printf(" %-5u ", -15);
	printf(" %-6u ", -16);
	printf(" %-1u ", -99);
	printf(" %-2u ", -100);
	printf(" %-3u ", -101);
	printf(" %-9u ", INT_MAX);
	printf(" %-10u ", INT_MIN);
	printf(" %-11u ", LONG_MAX);
	printf(" %-12u ", LONG_MIN);
	printf(" %-13u ", UINT_MAX);
	printf(" %-14u ", ULONG_MAX);
	printf(" %-15u ", 9223372036854775807LL);
	printf(" %-9u %-10u %-11u %-12u %-13u %-14u %-15u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	ft_printf("\n %-1x ", 0);
	ft_printf(" %-2x ", -1);
	ft_printf(" %-3x ", 1);
	ft_printf(" %-4x ", 9);
	ft_printf(" %-1x ", 10);
	ft_printf(" %-2x ", 11);
	ft_printf(" %-3x ", 15);
	ft_printf(" %-4x ", 16);
	ft_printf(" %-5x ", 17);
	ft_printf(" %-1x ", 99);
	ft_printf(" %-2x ", 100);
	ft_printf(" %-3x ", 101);
	ft_printf(" %-1x ", -9);
	ft_printf(" %-2x ", -10);
	ft_printf(" %-3x ", -11);
	ft_printf(" %-4x ", -14);
	ft_printf(" %-5x ", -15);
	ft_printf(" %-6x ", -16);
	ft_printf(" %-1x ", -99);
	ft_printf(" %-2x ", -100);
	ft_printf(" %-3x ", -101);
	ft_printf(" %-9x ", INT_MAX);
	ft_printf(" %-10x ", INT_MIN);
	ft_printf(" %-11x ", LONG_MAX);
	ft_printf(" %-12x ", LONG_MIN);
	ft_printf(" %-13x ", UINT_MAX);
	ft_printf(" %-14x ", ULONG_MAX);
	ft_printf(" %-15x ", 9223372036854775807LL);
	ft_printf(" %-9x %-10x %-11x %-12x %-13x %-14x %-15x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\n %-1x ", 0);
	printf(" %-2x ", -1);
	printf(" %-3x ", 1);
	printf(" %-4x ", 9);
	printf(" %-1x ", 10);
	printf(" %-2x ", 11);
	printf(" %-3x ", 15);
	printf(" %-4x ", 16);
	printf(" %-5x ", 17);
	printf(" %-1x ", 99);
	printf(" %-2x ", 100);
	printf(" %-3x ", 101);
	printf(" %-1x ", -9);
	printf(" %-2x ", -10);
	printf(" %-3x ", -11);
	printf(" %-4x ", -14);
	printf(" %-5x ", -15);
	printf(" %-6x ", -16);
	printf(" %-1x ", -99);
	printf(" %-2x ", -100);
	printf(" %-3x ", -101);
	printf(" %-9x ", INT_MAX);
	printf(" %-10x ", INT_MIN);
	printf(" %-11x ", LONG_MAX);
	printf(" %-12x ", LONG_MIN);
	printf(" %-13x ", UINT_MAX);
	printf(" %-14x ", ULONG_MAX);
	printf(" %-15x ", 9223372036854775807LL);
	printf(" %-9x %-10x %-11x %-12x %-13x %-14x %-15x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	return EXIT_SUCCESS;
}
