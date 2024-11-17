/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:46:41 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/17 16:34:33 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_countcharhex(unsigned int hex)
{
	size_t	len;

	if (hex == 0)
		return (1);
	len = 0;
	while (hex)
	{
		hex /= 16;
		len++;
	}
	return (len);
}

void	ft_puthex_fd(unsigned int hex, int fd, int big)
{
	char	digit;

	if (hex / 16 > 0)
		ft_puthex_fd(hex / 16, fd, big);
	if (hex % 16 <= 9)
		digit = (hex % 16) + '0';
	else
	{
		if (big)
			digit = (hex % 16) + 'A' - 10;
		else
			digit = (hex % 16) + 'a' - 10;
	}
	ft_putchar_fd(digit, fd);
}

size_t	ft_puthexbroptions_fd(unsigned int hex, int fd, struct s_option options)
{
	int	len;

	len = ft_countcharhex(hex);
	if (options.specifier == 'X')
		ft_puthex_fd(hex, fd, 1);
	else
		ft_puthex_fd(hex, fd, 0);
	return (len);
}
