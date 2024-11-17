/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:24:45 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/17 17:25:29 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;

	ft_printf("|%1s|", "");
	ft_printf("|%-1s|", "");
	ft_printf("| %-2s|", "");
	ft_printf("|%-3s |", "");
	ft_printf("| %-0s |", "");
	ft_printf("| %-s |", "-");
	ft_printf("| %-1s %-2s |", "", "-");
	ft_printf("| %-3s %-4s |", " - ", "");
	ft_printf("| %-2s %-3s %-4s %-5s |", " - ", "", "4", "");
	ft_printf("| %-3s %-3s %-4s %-5s %-3s |", " - ", "", "4", "", "2 ");

	printf("\n");

	printf("|%1s|", "");
	printf("|%-1s|", "");
	printf("| %-2s|", "");
	printf("|%-3s |", "");
	printf("| %-0s |", "");
	printf("| %-s |", "-");
	printf("| %-1s %-2s |", "", "-");
	printf("| %-3s %-4s |", " - ", "");
	printf("| %-2s %-3s %-4s %-5s |", " - ", "", "4", "");
	printf("| %-3s %-3s %-4s %-5s %-3s |", " - ", "", "4", "", "2 ");

	return EXIT_SUCCESS;
}
