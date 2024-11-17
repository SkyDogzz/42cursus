/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:24:45 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/17 17:16:38 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;

	ft_printf("%-1c", '0');
	ft_printf(" %-2c ", '0');
	ft_printf(" %-3c", '0' - 256);
	ft_printf("%-4c ", '0' + 256);
	ft_printf(" %-1c %-2c %-3c ", '0', 0, '1');
	ft_printf(" %-1c %-2c %-3c ", ' ', ' ', ' ');
	ft_printf(" %-1c %-2c %-3c ", '1', '2', '3');
	ft_printf(" %-1c %-2c %-3c ", '2', '1', 0);
	ft_printf(" %-1c %-2c %-3c ", 0, '1', '2');

	printf("\n");

	printf("%-1c", '0');
	printf(" %-2c ", '0');
	printf(" %-3c", '0' - 256);
	printf("%-4c ", '0' + 256);
	printf(" %-1c %-2c %-3c ", '0', 0, '1');
	printf(" %-1c %-2c %-3c ", ' ', ' ', ' ');
	printf(" %-1c %-2c %-3c ", '1', '2', '3');
	printf(" %-1c %-2c %-3c ", '2', '1', 0);
	printf(" %-1c %-2c %-3c ", 0, '1', '2');

	return EXIT_SUCCESS;
}
