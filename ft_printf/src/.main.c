/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:37:03 by marvin            #+#    #+#             */
/*   Updated: 2024/11/14 13:23:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"
#include <limits.h>

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;

	ft_printf("Hello world!\n");
	ft_printf("H#ello world!\n");
	ft_printf("H% +ello world!\n");
	ft_printf("H% +10ello world!\n");
	ft_printf("H% 1#ello world!\n");
	ft_printf("H%+- 1#ello world!\n");
	ft_printf("H%+- 1#109.42dello world!\n");
	ft_printf("H%+- 1#109.42lello world!\n");
	ft_printf("H%+- 1#109.42llello world!\n");
	ft_printf("H%+- 1#109.42hello world!\n");
	ft_printf("H%+- 1#109.42hhello world!\n");
	ft_printf("H%+- 1#109.42hhdello world!\n");
	ft_printf("H%+- 1#109.42hdello world!\n");
	printf("%d %i %u\n", 11, 10, -10);
	ft_printf("%d %i %u\n", 11, 10, -10);
	ft_printf("%c\n", 'a');
	ft_printf("%s\n", "Hello World!");
	ft_printf("%p\n", "Hello World!");
	printf("%x\n", INT_MAX);
	printf("oct max %u\n", INT_MIN);
	printf("oct min %u\n", INT_MAX);
	printf("%x %X\n", 1000001, 1000000);
	ft_printf("%x %X\n", 1000001, 1000000);
	ft_printf("%%\n");
	printf("%%\n");
	printf("%-d|\n", 1000001);
	printf("%-9d|\n", 1000000);
	printf("%11d|\n", 1000000);
	printf("%011d|\n\n\n", 1000000);
	ft_printf("%-d|\n", 1000001);
	ft_printf("%-9d|\n", 1000000);
	ft_printf("%11d|\n", 1000000);
	ft_printf("%011d|\n\n", 1000000);
	printf("%-.5d|\n", 1000000);
	printf("%-9.4d|\n", 1000000);
	printf("%11.4d|\n", 1000000);
	printf("%011.4d|\n\n\n", 1000000);
	ft_printf("%-.5d|\n", 1000000);
	ft_printf("%-9.4d|\n", 1000000);
	ft_printf("%11.4d|\n", 1000000);
	ft_printf("%011.4d|\n", 1000000);
	void *p = &argc;
	printf("point |%p|\n", p);
	printf("point |%21p|\n", p);
	printf("point |%-19p|\n", p);
	ft_printf("point |%p|\n", p);
	ft_printf("point |%21p|\n", p);
	ft_printf("point |%-19p|\n", p);
	char c = 'a';
	printf("point |%c|\n", c);
	printf("point |%21c|\n", c);
	printf("point |%-19c|\n", c);
	ft_printf("point |%c|\n", c);
	ft_printf("point |%21c|\n",c);
	ft_printf("point |%-19c|\n", c);
	printf("|%21s|\n", "Hello world");
	printf("|%-19s|\n", "Hello world");
	ft_printf("|%21s|\n", "Hello world");
	ft_printf("|%-19s|\n", "Hello world");
	printf("|%u|\n", UINT_MAX);
	printf("|%21u|\n", UINT_MAX);
	printf("|%-19u|\n", UINT_MAX);
	printf("|%021u|\n", UINT_MAX);
	ft_printf("|%u|\n", UINT_MAX);
	ft_printf("|%21u|\n", UINT_MAX);
	ft_printf("|%-19u|\n", UINT_MAX);
	ft_printf("|%021u|\n", UINT_MAX);
	printf("%x %X\n", 1000001, 1000000);
	ft_printf("%x %X\n", 1000001, 1000000);
	printf("%x %X\n", INT_MAX, INT_MAX);
	printf("%x %X\n", INT_MIN, INT_MIN);
	printf("|%21x| |%20X|\n", INT_MAX, INT_MAX);
	printf("|%-19x| |%-20X|\n", INT_MAX, INT_MAX);
	printf("|%021x| |%020X|\n", INT_MAX, INT_MAX);
	/*printf("|% 21x| |% 20X|\n", INT_MAX, INT_MAX);*/
	ft_printf("%x %X\n", INT_MAX, INT_MAX);
	ft_printf("%x %X\n", INT_MIN, INT_MIN);
	ft_printf("|%21x| |%20X|\n", INT_MAX, INT_MAX);
	ft_printf("|%-19x| |%-20X|\n", INT_MAX, INT_MAX);
	ft_printf("|%021x| |%020X|\n", INT_MAX, INT_MAX);
	ft_printf("|% 21x| |% 20X|\n", INT_MAX, INT_MAX);
	return (EXIT_SUCCESS);
}
