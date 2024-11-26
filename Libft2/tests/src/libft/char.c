/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:22:40 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/26 18:27:14 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/test.h"
#include "../../../include/libft.h"
#include <ctype.h>
#include <limits.h>

int	test_charis(const char *name, int (*f1)(int), int (*f2)(int), int fd)
{
	int	c;
	int	r1;
	int	r2;
	int	errors;

	c = -1;
	errors = 0;
	while (c <= 255)
	{
		r1 = f1(c);
		r2 = f2(c);
		if ((r1 && 1) != (r2 && 1))
		{
			ft_dprintf(fd, "Error when c = %d, expected %d, got %d in %s\n", c, r1, r2, name);
			errors++;
		}
		c++;
	}
	return (errors);
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
	close(fd);
	return (errors);
}
