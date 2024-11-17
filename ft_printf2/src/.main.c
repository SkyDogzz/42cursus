/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:24:45 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/17 22:41:49 by skydogzz         ###   ########.fr       */
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

	/*a = ft_printf("|%01d", 0);*/
	/*ft_printf("|%02d", -1);*/
	/*ft_printf("|%04d", 9);*/
	a = ft_printf("|%01d", 10);
	/*ft_printf("|%02d", 11);*/
	/*ft_printf("|%03d", 15);*/
	/*ft_printf("|%04d", 16);*/
	/*ft_printf("|%05d", 17);*/
	/*ft_printf("|%01d\n", 99);*/
	
	/*b = printf("|%01d", 0);*/
	/*printf("|%02d", -1);*/
	/*printf("|%04d", 9);*/
	b = printf("|%01d", 10);
	/*printf("|%02d", 11);*/
	/*printf("|%03d", 15);*/
	/*printf("|%04d", 16);*/
	/*printf("|%05d", 17);*/
	/*printf("|%01d", 99);*/

	printf("\n\n%d, %d\n\n", a, b);
	
	return EXIT_SUCCESS;
}
