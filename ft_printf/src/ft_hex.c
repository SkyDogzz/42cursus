/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:09:12 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 18:12:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	ft_puthex_fd_options(int n, int fd, struct s_option options)
{
	ft_puthex_fd(n, options.specifier, fd);
}

// NEED FIX
void	ft_puthex_fd(int n, char spe, int fd)
{
	char	num;

	if (n / 16 < 0 && n / 16 > -16)
		write(1, "-", 1);
	if (n / 16 > 0 | n / 16 < 0)
	{
		ft_puthex_fd(n / 16, fd, spe);
	}
	num = n % 16;
	if (num < 0)
		num *= -1;
	if (num <= 9)
		num += '0';
	else
	{
		if (spe == 'x')
			num += 'a' - 10;
		else
		{
			num += 'A' - 10;
		}
	}
	write(fd, &num, 1);
}
