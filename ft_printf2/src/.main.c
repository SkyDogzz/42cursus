/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:24:45 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/15 17:11:41 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
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

	printf("%d %d\n", a, b);
	return EXIT_SUCCESS;
}
