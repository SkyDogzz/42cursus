/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:51:48 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/26 17:31:42 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/test.h"

int	test_libft(void)
{
	size_t	errors;

	errors = 0;
	errors += test_char();
	return (errors);
}

int	test_ftprintf(void)
{
	size_t	errors;

	errors = 0;
	return (errors);
}

int	test_getnextline(void)
{	
	size_t	errors;

	errors = 0;
	return (errors);
}

int	main(void)
{
	int	error[3];

	error[0] = test_libft();
	error[1] = test_ftprintf();
	error[2] = test_getnextline();
	ft_printf("%d erreurs au totals!\n", ft_gettotal(error, 3));

	return (EXIT_SUCCESS);
}
