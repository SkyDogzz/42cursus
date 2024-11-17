/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:24:45 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/17 18:28:15 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;

	ft_printf(" %01d ", 0);
	ft_printf(" %02d ", -1);
	ft_printf(" %04d ", 9);
	ft_printf(" %01d ", 10);
	ft_printf(" %02d ", 11);
	ft_printf(" %03d ", 15);
	ft_printf(" %04d ", 16);
	ft_printf(" %05d ", 17);
	ft_printf(" %01d ", 99);
	ft_printf(" %02d ", 100);
	ft_printf(" %03d ", 101);
	ft_printf(" %01d ", -9);
	ft_printf(" %02d ", -10);
	ft_printf(" %03d ", -11);
	ft_printf(" %04d ", -14);
	ft_printf(" %05d ", -15);
	ft_printf(" %06d ", -16);
	ft_printf(" %01d ", -99);
	ft_printf(" %02d ", -100);
	ft_printf(" %03d ", -101);
	ft_printf(" %09d ", INT_MAX);
	ft_printf(" %010d ", INT_MIN);
	ft_printf(" %011d ", LONG_MAX);
	ft_printf(" %012d ", LONG_MIN);
	ft_printf(" %013d ", UINT_MAX);
	ft_printf(" %014d ", ULONG_MAX);
	ft_printf(" %015d ", 9223372036854775807LL);
	ft_printf(" %09d %010d %011d %012d %013d %014d %015d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf(" %01d ", 0);
	printf(" %02d ", -1);
	printf(" %04d ", 9);
	printf(" %01d ", 10);
	printf(" %02d ", 11);
	printf(" %03d ", 15);
	printf(" %04d ", 16);
	printf(" %05d ", 17);
	printf(" %01d ", 99);
	printf(" %02d ", 100);
	printf(" %03d ", 101);
	printf(" %01d ", -9);
	printf(" %02d ", -10);
	printf(" %03d ", -11);
	printf(" %04d ", -14);
	printf(" %05d ", -15);
	printf(" %06d ", -16);
	printf(" %01d ", -99);
	printf(" %02d ", -100);
	printf(" %03d ", -101);
	printf(" %09d ", INT_MAX);
	printf(" %010d ", INT_MIN);
	printf(" %011d ", LONG_MAX);
	printf(" %012d ", LONG_MIN);
	printf(" %013d ", UINT_MAX);
	printf(" %014d ", ULONG_MAX);
	printf(" %015d ", 9223372036854775807LL);
	printf(" %09d %010d %011d %012d %013d %014d %015d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	return EXIT_SUCCESS;
}
