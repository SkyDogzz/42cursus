/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:24:45 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/18 01:43:25 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <limits.h>

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;

	int a, b;

	a = ft_printf(" %+d ", 0);
	/*ft_printf(" %+d ", -1);*/
	/*ft_printf(" %+d ", 9);*/
	/*ft_printf(" %+d ", 10);*/
	/*ft_printf(" %+d ", 11);*/
	/*ft_printf(" %+d ", 15);*/
	/*ft_printf(" %+d ", 16);*/
	/*ft_printf(" %+d ", 17);*/
	/*ft_printf(" %+d ", 99);*/
	printf("\n");
	b = printf(" %+d ", 0);
	/*printf(" %+d ", -1);*/
	/*printf(" %+d ", 9);*/
	/*printf(" %+d ", 10);*/
	/*printf(" %+d ", 11);*/
	/*printf(" %+d ", 15);*/
	/*printf(" %+d ", 16);*/
	/*printf(" %+d ", 17);*/
	/*printf(" %+d ", 99);	*/
	
	printf("\n\n%d, %d\n\n", a, b);
	
	return EXIT_SUCCESS;
}
