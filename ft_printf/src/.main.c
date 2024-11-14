/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:37:03 by marvin            #+#    #+#             */
/*   Updated: 2024/11/14 18:08:30 by marvin           ###   ########.fr       */
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

void test_u()
{
	int a, b;
	ft_printf(" %-1u ", 0);
	a = ft_printf("| %-2u |", -1);
	ft_printf(" %-3u ", 1);
	ft_printf(" %-4u ", 9);
	ft_printf(" %-1u ", 10);
	ft_printf(" %-2u ", 11);
	ft_printf(" %-3u ", 15);
	ft_printf(" %-4u ", 16);
	ft_printf(" %-5u ", 17);
	ft_printf(" %-1u ", 99);
	ft_printf(" %-2u ", 100);
	ft_printf(" %-3u ", 101);
	ft_printf(" %-1u ", -9);
	ft_printf(" %-2u ", -10);
	ft_printf(" %-3u ", -11);
	ft_printf(" %-4u ", -14);
	ft_printf(" %-5u ", -15);
	ft_printf(" %-6u ", -16);
	ft_printf(" %-1u ", -99);
	ft_printf(" %-2u ", -100);
	ft_printf(" %-3u ", -101);
	ft_printf(" %-9u ", INT_MAX);
	ft_printf(" %-10u ", INT_MIN);
	ft_printf(" %-11u ", LONG_MAX);
	ft_printf(" %-12u ", LONG_MIN);
	ft_printf(" %-13u ", UINT_MAX);
	ft_printf(" %-14u ", ULONG_MAX);
	ft_printf(" %-15u ", 9223372036854775807LL);
	ft_printf(" %-9u %-10u %-11u %-12u %-13u %-14u %-15u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	write(1, "\n", 1);

	printf(" %-1u ", 0);
	b = printf("| %-2u |", -1);
	printf(" %-3u ", 1);
	printf(" %-4u ", 9);
	printf(" %-1u ", 10);
	printf(" %-2u ", 11);
	printf(" %-3u ", 15);
	printf(" %-4u ", 16);
	printf(" %-5u ", 17);
	printf(" %-1u ", 99);
	printf(" %-2u ", 100);
	printf(" %-3u ", 101);
	printf(" %-1u ", -9);
	printf(" %-2u ", -10);
	printf(" %-3u ", -11);
	printf(" %-4u ", -14);
	printf(" %-5u ", -15);
	printf(" %-6u ", -16);
	printf(" %-1u ", -99);
	printf(" %-2u ", -100);
	printf(" %-3u ", -101);
	printf(" %-9u ", INT_MAX);
	printf(" %-10u ", INT_MIN);
	printf(" %-11u ", LONG_MAX);
	printf(" %-12u ", LONG_MIN);
	printf(" %-13u ", UINT_MAX);
	printf(" %-14u ", ULONG_MAX);
	printf(" %-15u ", 9223372036854775807LL);
	printf(" %-9u %-10u %-11u %-12u %-13u %-14u %-15u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\n%d, %d\n", a, b);
}

void test_xX()
{
	int a, b;
	ft_printf(" %-1x ", 0);
	a = ft_printf("| %-2x |", -1);
	ft_printf(" %-3x ", 1);
	ft_printf(" %-4x ", 9);
	ft_printf(" %-1x ", 10);
	ft_printf(" %-2x ", 11);
	ft_printf(" %-3x ", 15);
	ft_printf(" %-4x ", 16);
	ft_printf(" %-5x ", 17);
	ft_printf(" %-1x ", 99);
	ft_printf(" %-2x ", 100);
	ft_printf(" %-3x ", 101);
	ft_printf(" %-1x ", -9);
	ft_printf(" %-2x ", -10);
	ft_printf(" %-3x ", -11);
	ft_printf(" %-4x ", -14);
	ft_printf(" %-5x ", -15);
	ft_printf(" %-6x ", -16);
	ft_printf(" %-1x ", -99);
	ft_printf(" %-2x ", -100);
	ft_printf(" %-3x ", -101);
	ft_printf(" %-9x ", INT_MAX);
	ft_printf(" %-10x ", INT_MIN);
	ft_printf(" %-11x ", LONG_MAX);
	ft_printf(" %-12x ", LONG_MIN);
	ft_printf(" %-13x ", UINT_MAX);
	ft_printf(" %-14x ", ULONG_MAX);
	ft_printf(" %-15x ", 9223372036854775807LL);
	ft_printf(" %-9x %-10x %-11x %-12x %-13x %-14x %-15x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	
	write(1, "\n", 1);

	printf(" %-1x ", 0);
	b = printf("| %-2x |", -1);
	printf(" %-3x ", 1);
	printf(" %-4x ", 9);
	printf(" %-1x ", 10);
	printf(" %-2x ", 11);
	printf(" %-3x ", 15);
	printf(" %-4x ", 16);
	printf(" %-5x ", 17);
	printf(" %-1x ", 99);
	printf(" %-2x ", 100);
	printf(" %-3x ", 101);
	printf(" %-1x ", -9);
	printf(" %-2x ", -10);
	printf(" %-3x ", -11);
	printf(" %-4x ", -14);
	printf(" %-5x ", -15);
	printf(" %-6x ", -16);
	printf(" %-1x ", -99);
	printf(" %-2x ", -100);
	printf(" %-3x ", -101);
	printf(" %-9x ", INT_MAX);
	printf(" %-10x ", INT_MIN);
	printf(" %-11x ", LONG_MAX);
	printf(" %-12x ", LONG_MIN);
	printf(" %-13x ", UINT_MAX);
	printf(" %-14x ", ULONG_MAX);
	printf(" %-15x ", 9223372036854775807LL);
	printf(" %-9x %-10x %-11x %-12x %-13x %-14x %-15x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\n%d, %d\n", a, b);
}

void test_pr()
{
	int a, b;
a = ft_printf(" %% ");
ft_printf(" %%%% ");
ft_printf(" %% %% %% ");
ft_printf(" %%  %%  %% ");
ft_printf(" %%   %%   %% ");
ft_printf("%%");
ft_printf("%% %%");
	write(1, "\n", 1);
b =	printf(" %% ");
 printf(" %%%% ");
printf(" %% %% %% ");
printf(" %%  %%  %% ");
printf(" %%   %%   %% ");
printf("%%");
printf("%% %%");
	printf("\n%d, %d\n", a, b);
}

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;

	/*test_char();*/
	/*test_str();*/
	/*test_p();*/
	/*test_u();*/
	/*test_xX();*/
	/*test_pr();*/
printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	return (EXIT_SUCCESS);
}
