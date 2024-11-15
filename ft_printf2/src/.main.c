/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:24:45 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/15 17:35:16 by skydogzz         ###   ########.fr       */
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
	a = printf("%p\n", (void *)-1023);
	b = ft_printf("%p\n", (void *)-1023);
	printf("%d %i\n", -1023, -1023);
	ft_printf("%d %i\n", -1023, -1023);
	printf("%x %X\n", -1023, -1023);
	printf("%x %X\n", 1023, 1023);
	ft_printf("%x %X\n", -1023, -1023);
	ft_printf("%x %X\n", 1023, 1023);

	ft_printf(" %p ", -1);
	ft_printf(" %p ", 1);
	ft_printf(" %p ", 15);
	ft_printf(" %p ", 16);
	ft_printf(" %p ", 17);
	ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
	ft_printf(" %p %p ", INT_MIN, INT_MAX);
	ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	ft_printf(" %p %p ", 0, 0);
	
	write(1, "\n", 1);

	printf(" %p ", -1);
	printf(" %p ", 1);
	printf(" %p ", 15);
	printf(" %p ", 16);
	printf(" %p ", 17);
	printf(" %p %p ", LONG_MIN, LONG_MAX);
	printf(" %p %p ", INT_MIN, INT_MAX);
	printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	printf(" %p %p ", 0, 0);

	return EXIT_SUCCESS;
}
