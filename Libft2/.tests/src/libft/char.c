/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:22:40 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/26 18:58:43 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/test.h"
#include "../../../include/libft.h"
#include <ctype.h>
#include <limits.h>

static int	test_charis(const char *name, int (*f1)(int), int (*f2)(int),
	int fd)
{
	int	c;
	int	r1;
	int	r2;
	int	errors;

	c = -256;
	errors = 0;
	while (c <= 255)
	{
		r1 = f1(c);
		r2 = f2(c);
		if ((r1 && 1) != (r2 && 1))
		{
			ft_dprintf(fd, "Error when c = %d, expected %d, got %d in %s\n", c,
				r1, r2, name);
			errors++;
		}
		c++;
	}
	if (errors == 0)
		ft_dprintf(fd, "All tests for %s: OK\n", name);
	return (errors);
}

static void	test_ft_swapcase(int fd)
{
	const char	*test1 = "abc";
	const char	*expected1 = "ABC";
	ft_dprintf(fd, "Swapcase test 1: %s -> %s | %s\n", test1, ft_swapcase(test1),
			ft_strncmp(ft_swapcase(test1), expected1, ft_strlen(expected1)) == 0 ? "OK" : "FAIL");
	const char	*test2 = "XYZ";
	const char	*expected2 = "xyz";
	ft_dprintf(fd, "Swapcase test 2: %s -> %s | %s\n", test2, ft_swapcase(test2),
			ft_strncmp(ft_swapcase(test2), expected2, ft_strlen(expected2)) == 0 ? "OK" : "FAIL");
	const char	*test3 = "Hello World!";
	const char	*expected3 = "hELLO wORLD!";
	ft_dprintf(fd, "Swapcase test 3: %s -> %s | %s\n", test3, ft_swapcase(test3),
			ft_strncmp(ft_swapcase(test3), expected3, ft_strlen(expected3)) == 0 ? "OK" : "FAIL");
	const char	*test4 = "";
	const char	*expected4 = "";
	ft_dprintf(fd, "Swapcase test 4: %s -> %s | %s\n", test4, ft_swapcase(test4),
			ft_strncmp(ft_swapcase(test4), expected4, ft_strlen(expected4)) == 0 ? "OK" : "FAIL");
	const char	*test5 = "123!@#";
	const char	*expected5 = "123!@#";
	ft_dprintf(fd, "Swapcase test 5: %s -> %s | %s\n", test5, ft_swapcase(test5),
			ft_strncmp(ft_swapcase(test5), expected5, ft_strlen(expected5)) == 0 ? "OK" : "FAIL");
	const char	*test6 = NULL;
	ft_dprintf(fd, "Swapcase test 6: NULL -> %s | %s\n",
			ft_swapcase(test6) == NULL ? "NULL" : "Unexpected output",
			ft_swapcase(test6) == NULL ? "OK" : "FAIL");
	const char	*test7 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	const char	*expected7 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	ft_dprintf(fd, "Swapcase test 7: %s -> %s | %s\n", test7, ft_swapcase(test7),
			ft_strncmp(ft_swapcase(test7), expected7, ft_strlen(expected7)) == 0 ? "OK" : "FAIL");
}

int test_char(void)
{
	int	errors;
	int	fd;

	fd = open("log/char.log", O_CREAT|O_RDWR, 0644);
	errors = 0;
	errors += test_charis("ft_isalnum", &isalnum, &ft_isalnum, fd);
	errors += test_charis("ft_isalpha", &isalpha, &ft_isalpha, fd);
	// errors += test_charis("ft_isascii", &isascii, &ft_isascii, fd);
	errors += test_charis("ft_isblank", &isblank, &ft_isblank, fd);
	errors += test_charis("ft_isdigit", &isdigit, &ft_isdigit, fd);
	errors += test_charis("ft_islower", &islower, &ft_islower, fd);
	errors += test_charis("ft_isprint", &isprint, &ft_isprint, fd);
	errors += test_charis("ft_isspace", &isspace, &ft_isspace, fd);
	errors += test_charis("ft_isupper", &isupper, &ft_isupper, fd);
	errors += test_charis("ft_toupper", &toupper, &ft_toupper, fd);
	errors += test_charis("ft_tolower", &tolower, &ft_tolower, fd);
	test_ft_swapcase(fd);
	close(fd);
	return (errors);
}
