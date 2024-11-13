/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:37:03 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 17:58:10 by marvin           ###   ########.fr       */
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
	ft_printf("H% +09ello world!\n");
	ft_printf("H% 0#ello world!\n");
	ft_printf("H%+- 0#ello world!\n");
	ft_printf("H%+- 0#109.42dello world!\n");
	ft_printf("H%+- 0#109.42lello world!\n");
	ft_printf("H%+- 0#109.42llello world!\n");
	ft_printf("H%+- 0#109.42hello world!\n");
	ft_printf("H%+- 0#109.42hhello world!\n");
	ft_printf("H%+- 0#109.42hhdello world!\n");
	ft_printf("H%+- 0#109.42hdello world!\n");
	printf("%d %i %u\n", 10, 10, -10);
	ft_printf("%d %i %u\n", 10, 10, -10);
	ft_printf("%c\n", 'a');
	ft_printf("%s\n", "Hello World!");
	ft_printf("%p\n", "Hello World!");
	printf("%x\n", INT_MAX);
	printf("oct max %u\n", INT_MIN);
	printf("oct min %u\n", INT_MAX);
	printf("%x %X\n", 1000000, 1000000);
	ft_printf("%x %X\n", 1000000, 1000000);
	ft_printf("%%\n");
	printf("%%\n");
	printf("%-d|\n", 1000000);
	printf("%-10d|\n", 1000000);
	printf("%10d|\n", 1000000);
	printf("%010d|\n\n\n", 1000000);
	ft_printf("%-d|\n", 1000000);
	ft_printf("%-10d|\n", 1000000);
	ft_printf("%10d|\n", 1000000);
	ft_printf("%010d|\n\n", 1000000);
	printf("%-.4d|\n", 1000000);
	printf("%-10.4d|\n", 1000000);
	printf("%10.4d|\n", 1000000);
	printf("%010.4d|\n\n\n", 1000000);
	ft_printf("%-.4d|\n", 1000000);
	ft_printf("%-10.4d|\n", 1000000);
	ft_printf("%10.4d|\n", 1000000);
	ft_printf("%010.4d|\n", 1000000);
	void *p = &argc;
	printf("point |%p|\n", p);
	printf("point |%20p|\n", p);
	printf("point |%-20p|\n", p);
	ft_printf("point |%p|\n", p);
	ft_printf("point |%20p|\n", p);
	ft_printf("point |%-20p|\n", p);
	char c = 'a';
	printf("point |%c|\n", c);
	printf("point |%20c|\n", c);
	printf("point |%-20c|\n", c);
	ft_printf("point |%c|\n", c);
	ft_printf("point |%20c|\n",c);
	ft_printf("point |%-20c|\n", c);
	printf("|%20s|\n", "Hello world");
	printf("|%-20s|\n", "Hello world");
	printf("|%020s|\n", "Hello world");
	ft_printf("|%20s|\n", "Hello world");
	ft_printf("|%-20s|\n", "Hello world");
	ft_printf("|%020s|\n", "Hello world");
	return (EXIT_SUCCESS);
}
