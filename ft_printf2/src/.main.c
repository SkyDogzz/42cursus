/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:24:45 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/17 19:14:56 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;

	ft_printf(" %+d ", 0);
	ft_printf(" %+d ", -1);
	ft_printf(" %+d ", 9);
	ft_printf(" %+d ", 10);
	ft_printf(" %+d ", 11);
	ft_printf(" %+d ", 15);
	ft_printf(" %+d ", 16);
	ft_printf(" %+d ", 17);
	ft_printf(" %+d ", 99);
	ft_printf(" %+d ", 100);
	ft_printf(" %+d ", 101);
	ft_printf(" %+d ", -9);
	ft_printf(" %+d ", -10);
	ft_printf(" %+d ", -11);
	ft_printf(" %+d ", -14);
	ft_printf(" %+d ", -15);
	ft_printf(" %+d ", -16);
	ft_printf(" %+d ", -99);
	ft_printf(" %+d ", -100);
	ft_printf(" %+d ", -101);
	ft_printf(" %+d ", INT_MAX);
	ft_printf(" %+d ", INT_MIN);
	ft_printf(" %+d ", LONG_MAX);
	ft_printf(" %+d ", LONG_MIN);
	ft_printf(" %+d ", UINT_MAX);
	ft_printf(" %+d ", ULONG_MAX);
	ft_printf(" %+d ", 9223372036854775807LL);
	ft_printf(" %+d %+d %+d %+d %+d %+d %+d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf(" %+i ", 0);
	ft_printf(" %+i ", -1);
	ft_printf(" %+i ", 1);
	ft_printf(" %+i ", 9);
	ft_printf(" %+i ", 10);
	ft_printf(" %+i ", 11);
	ft_printf(" %+i ", 15);
	ft_printf(" %+i ", 16);
	ft_printf(" %+i ", 17);
	ft_printf(" %+i ", 99);
	ft_printf(" %+i ", 100);
	ft_printf(" %+i ", 101);
	ft_printf(" %+i ", -9);
	ft_printf(" %+i ", -10);
	ft_printf(" %+i ", -11);
	ft_printf(" %+i ", -14);
	ft_printf(" %+i ", -15);
	ft_printf(" %+i ", -16);
	ft_printf(" %+i ", -99);
	ft_printf(" %+i ", -100);
	ft_printf(" %+i ", -101);
	ft_printf(" %+i ", INT_MAX);
	ft_printf(" %+i ", INT_MIN);
	ft_printf(" %+i ", LONG_MAX);
	ft_printf(" %+i ", LONG_MIN);
	ft_printf(" %+i ", UINT_MAX);
	ft_printf(" %+i ", ULONG_MAX);
	ft_printf(" %+i ", 9223372036854775807LL);
	ft_printf(" %+i %+i %+i %+i %+i %+i %+i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\n %+d ", 0);
	printf(" %+d ", -1);
	printf(" %+d ", 9);
	printf(" %+d ", 10);
	printf(" %+d ", 11);
	printf(" %+d ", 15);
	printf(" %+d ", 16);
	printf(" %+d ", 17);
	printf(" %+d ", 99);
	printf(" %+d ", 100);
	printf(" %+d ", 101);
	printf(" %+d ", -9);
	printf(" %+d ", -10);
	printf(" %+d ", -11);
	printf(" %+d ", -14);
	printf(" %+d ", -15);
	printf(" %+d ", -16);
	printf(" %+d ", -99);
	printf(" %+d ", -100);
	printf(" %+d ", -101);
	printf(" %+d ", INT_MAX);
	printf(" %+d ", INT_MIN);
	printf(" %+d ", LONG_MAX);
	printf(" %+d ", LONG_MIN);
	printf(" %+d ", UINT_MAX);
	printf(" %+d ", ULONG_MAX);
	printf(" %+d ", 9223372036854775807LL);
	printf(" %+d %+d %+d %+d %+d %+d %+d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf(" %+i ", 0);
	printf(" %+i ", -1);
	printf(" %+i ", 1);
	printf(" %+i ", 9);
	printf(" %+i ", 10);
	printf(" %+i ", 11);
	printf(" %+i ", 15);
	printf(" %+i ", 16);
	printf(" %+i ", 17);
	printf(" %+i ", 99);
	printf(" %+i ", 100);
	printf(" %+i ", 101);
	printf(" %+i ", -9);
	printf(" %+i ", -10);
	printf(" %+i ", -11);
	printf(" %+i ", -14);
	printf(" %+i ", -15);
	printf(" %+i ", -16);
	printf(" %+i ", -99);
	printf(" %+i ", -100);
	printf(" %+i ", -101);
	printf(" %+i ", INT_MAX);
	printf(" %+i ", INT_MIN);
	printf(" %+i ", LONG_MAX);
	printf(" %+i ", LONG_MIN);
	printf(" %+i ", UINT_MAX);
	printf(" %+i ", ULONG_MAX);
	printf(" %+i ", 9223372036854775807LL);
	printf(" %+i %+i %+i %+i %+i %+i %+i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	return EXIT_SUCCESS;
}
