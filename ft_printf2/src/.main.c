/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:24:45 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/17 19:38:36 by skydogzz         ###   ########.fr       */
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

	printf(" %#x ", 0);
	a = printf(" %#x ", -1);
	printf(" %#x ", 1);
	printf(" %#x ", 9);
	printf(" %#x ", 10);
	printf(" %#x ", 11);
	printf(" %#x ", 15);
	printf(" %#x ", 16);
	printf(" %#x ", 17);
	printf(" %#x ", 99);
	printf(" %#x ", 100);
	printf(" %#x ", 101);
	printf(" %#x ", -9);
	printf(" %#x ", -10);
	printf(" %#x ", -11);
	printf(" %#x ", -14);
	printf(" %#x ", -15);
	printf(" %#x ", -16);
	printf(" %#x ", -99);
	printf(" %#x ", -100);
	printf(" %#x ", -101);
	printf(" %#x ", INT_MAX);
	printf(" %#x ", INT_MIN);
	printf(" %#x ", LONG_MAX);
	printf(" %#x ", LONG_MIN);
	printf(" %#x ", UINT_MAX);
	printf(" %#x ", ULONG_MAX);
	printf(" %#x ", 9223372036854775807LL);
	printf(" %#x %#x %#x %#x %#x %#x %#x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf(" %#x%#x ", INT_MAX, INT_MIN);
	printf(" %#X ", 0);
	printf(" %#X ", -1);
	printf(" %#X ", 1);
	printf(" %#X ", 9);
	printf(" %#X ", 10);
	printf(" %#X ", 11);
	printf(" %#X ", 15);
	printf(" %#X ", 16);
	printf(" %#X ", 17);
	printf(" %#X ", 99);
	printf(" %#X ", 100);
	printf(" %#X ", 101);
	printf(" %#X ", -9);
	printf(" %#X ", -10);
	printf(" %#X ", -11);
	printf(" %#X ", -14);
	printf(" %#X ", -15);
	printf(" %#X ", -16);
	printf(" %#X ", -99);
	printf(" %#X ", -100);
	printf(" %#X ", -101);
	printf(" %#X ", INT_MAX);
	printf(" %#X ", INT_MIN);
	printf(" %#X ", LONG_MAX);
	printf(" %#X ", LONG_MIN);
	printf(" %#X ", UINT_MAX);
	printf(" %#X ", ULONG_MAX);
	printf(" %#X ", 9223372036854775807LL);
	printf(" %#X %#X %#X %#X %#X %#X %#X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);	
	ft_printf("\n\n %#x ", 0);
	b = ft_printf(" %#x ", -1);
	ft_printf(" %#x ", 1);
	ft_printf(" %#x ", 9);
	ft_printf(" %#x ", 10);
	ft_printf(" %#x ", 11);
	ft_printf(" %#x ", 15);
	ft_printf(" %#x ", 16);
	ft_printf(" %#x ", 17);
	ft_printf(" %#x ", 99);
	ft_printf(" %#x ", 100);
	ft_printf(" %#x ", 101);
	ft_printf(" %#x ", -9);
	ft_printf(" %#x ", -10);
	ft_printf(" %#x ", -11);
	ft_printf(" %#x ", -14);
	ft_printf(" %#x ", -15);
	ft_printf(" %#x ", -16);
	ft_printf(" %#x ", -99);
	ft_printf(" %#x ", -100);
	ft_printf(" %#x ", -101);
	ft_printf(" %#x ", INT_MAX);
	ft_printf(" %#x ", INT_MIN);
	ft_printf(" %#x ", LONG_MAX);
	ft_printf(" %#x ", LONG_MIN);
	ft_printf(" %#x ", UINT_MAX);
	ft_printf(" %#x ", ULONG_MAX);
	ft_printf(" %#x ", 9223372036854775807LL);
	ft_printf(" %#x %#x %#x %#x %#x %#x %#x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf(" %#x%#x ", INT_MAX, INT_MIN);
	ft_printf(" %#X ", 0);
	ft_printf(" %#X ", -1);
	ft_printf(" %#X ", 1);
	ft_printf(" %#X ", 9);
	ft_printf(" %#X ", 10);
	ft_printf(" %#X ", 11);
	ft_printf(" %#X ", 15);
	ft_printf(" %#X ", 16);
	ft_printf(" %#X ", 17);
	ft_printf(" %#X ", 99);
	ft_printf(" %#X ", 100);
	ft_printf(" %#X ", 101);
	ft_printf(" %#X ", -9);
	ft_printf(" %#X ", -10);
	ft_printf(" %#X ", -11);
	ft_printf(" %#X ", -14);
	ft_printf(" %#X ", -15);
	ft_printf(" %#X ", -16);
	ft_printf(" %#X ", -99);
	ft_printf(" %#X ", -100);
	ft_printf(" %#X ", -101);
	ft_printf(" %#X ", INT_MAX);
	ft_printf(" %#X ", INT_MIN);
	ft_printf(" %#X ", LONG_MAX);
	ft_printf(" %#X ", LONG_MIN);
	ft_printf(" %#X ", UINT_MAX);
	ft_printf(" %#X ", ULONG_MAX);
	ft_printf(" %#X ", 9223372036854775807LL);
	ft_printf(" %#X %#X %#X %#X %#X %#X %#X\n\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	printf("\n\n%d, %d\n\n", a, b);
	return EXIT_SUCCESS;
}
