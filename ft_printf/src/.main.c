/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:37:03 by marvin            #+#    #+#             */
/*   Updated: 2024/11/14 17:29:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"
#include <limits.h>

void	test_char()
{
	ft_printf(" %-2c ", '0');
	ft_printf(" %-3c", '0' - 256);
	ft_printf("%-4c ", '0' + 256);
	ft_printf(" %-1c %-2c %-3c ", '0', 0, '1');
	ft_printf(" %-1c %-2c %-3c ", ' ', ' ', ' ');
	ft_printf(" %-1c %-2c %-3c ", '1', '2', '3');
	ft_printf(" %-1c %-2c %-3c ", '2', '1', 0);
	ft_printf(" %-1c %-2c %-3c ", 0, '1', '2');

	write(1, "\n", 1);

	printf(" %-2c ", '0');
	printf(" %-3c", '0' - 256);
	printf("%-4c ", '0' + 256);
	printf(" %-1c %-2c %-3c ", '0', 0, '1');
	printf(" %-1c %-2c %-3c ", ' ', ' ', ' ');
	printf(" %-1c %-2c %-3c ", '1', '2', '3');
	printf(" %-1c %-2c %-3c ", '2', '1', 0);
	printf(" %-1c %-2c %-3c ", 0, '1', '2');
}

void	test_str()
{
	int a, b;
	ft_printf("%1s", "");
	ft_printf("%-1s", "");
	ft_printf(" %-2s", "");
	ft_printf("%-3s ", "");
	ft_printf(" %-0s ", "");
	ft_printf(" %-s ", "-");
	ft_printf(" %-1s %-2s ", "", "-");
	ft_printf(" %-3s %-4s ", " - ", "");
	ft_printf(" %-2s %-3s %-4s %-5s ", " - ", "", "4", "");
	a = ft_printf(" %-3s %-3s %-4s %-5s %-3s ", " - ", "", "4", "", "2 ");

	write(1, "\n", 1);

	ft_printf("%1s", "");
	ft_printf("%-1s", "");
	ft_printf(" %-2s", "");
	ft_printf("%-3s ", "");
	ft_printf(" %-0s ", "");
	ft_printf(" %-s ", "-");
	ft_printf(" %-1s %-2s ", "", "-");
	ft_printf(" %-3s %-4s ", " - ", "");
	ft_printf(" %-2s %-3s %-4s %-5s ", " - ", "", "4", "");
	b = ft_printf(" %-3s %-3s %-4s %-5s %-3s ", " - ", "", "4", "", "2 ");

	printf("\n%d, %d\n", a, b);
}

void test_p(void)
{
	int a, b;
	ft_printf("| %2p ", -1);
	ft_printf("| %-2p ", -1);
	ft_printf("| %-2p ", 1);
	ft_printf("| %-2p ", 15);
	ft_printf("| %-3p ", 16);
	ft_printf("| %-4p ", 17);
	ft_printf("| %-9p %-10p ", LONG_MIN, LONG_MAX);
	ft_printf("| %-11p %-12p ", INT_MIN, INT_MAX);
	ft_printf("| %-13p %-14p ", ULONG_MAX, -ULONG_MAX);
	a = ft_printf("| %-1p %-2p |", 0, 0);

	write(1, "\n", 1);

	printf("| %2p ", -1);
	printf("| %-2p ", -1);
	printf("| %-2p ", 1);
	printf("| %-2p ", 15);
	printf("| %-3p ", 16);
	printf("| %-4p ", 17);
	printf("| %-9p %-10p ", LONG_MIN, LONG_MAX);
	printf("| %-11p %-12p ", INT_MIN, INT_MAX);
	printf("| %-13p %-14p ", ULONG_MAX, -ULONG_MAX);
	b = printf("| %-1p %-2p |", 0, 0);
	printf("\n%d, %d\n", a, b);
}

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;

	/*test_char();*/
	/*test_str();*/
	test_p();
	return (EXIT_SUCCESS);
}
