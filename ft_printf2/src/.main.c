/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:24:45 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/17 21:57:56 by skydogzz         ###   ########.fr       */
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

	a = ft_printf("| % d ", 0);
	a = ft_printf("| % d ", -1);
	a = ft_printf("| % d ", 1);
	ft_printf("| % d ", 9);
	a = ft_printf("| % d ", 10);
	ft_printf("| % i ", 0);
	ft_printf("| % i ", -1);
	ft_printf("| % i ", 1);
	ft_printf("| % i ", 9);
	ft_printf("| % i \n", 10);


	b = printf("| % d ", 0);
	b = printf("| % d ", -1);
	b = printf("| % d ", 1);
	printf("| % d ", 9);
	b = printf("| % d ", 10);
	printf("| % i ", 0);
	printf("| % i ", -1);
	printf("| % i ", 1);
	printf("| % i ", 9);
	printf("| % i ", 10);

	printf("\n\n%d, %d\n\n", a, b);
	
	printf("\n%d\n", ft_printf("% d", 0));
	printf("\n%d\n", printf("% d", 0));
	return EXIT_SUCCESS;
}
