/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:22:40 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/26 18:12:00 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/test.h"
#include <ctype.h>
#include <limits.h>

int	test_charis(int (*f1)(int), int (*f2)(int), int fd)
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
		if (r1 && 1 != r2 && 1)
		{
			ft_dprintf(fd, "Error when c = %d, expected %d, got %d\n", c, r1, r2);
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

	fd = open("log/char1.log", O_CREAT|O_RDWR, 0644);
	ft_printf("fd = %d\n", fd);
	errors = 0;
	errors = test_charis(&isalpha, &ft_isalpha, fd);
	close(fd);
	return (errors);
}
