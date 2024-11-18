/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:46:41 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/18 16:52:22 by marvin           ###   ########.fr       */
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

size_t	ft_getsizec(unsigned int hex, struct s_option options)
{
	size_t	len;

	if (options.precision < 0)
		len = options.width - ft_countcharhex(hex);
	else
	{
		len = options.precision - ft_countcharhex(hex);
	}
	return (len);
}

enum e_bool	ft_ismaj(char c)
{
	if (c == 'X')
		return (TRUE);
	return (FALSE);
}

size_t	ft_puthexbroptions_fd(unsigned int hex, int fd, struct s_option options)
{
	struct s_size	sizes;
	enum e_bool		maj;

	sizes.len = ft_countcharhex(hex) + (ft_getflag(options.flag, '#')
			&& hex) * 2;
	sizes.padded = ft_getsizec(hex, options);
	maj = ft_ismaj(options.specifier);
	if (ft_getflag(options.flag, '-'))
	{
		ft_putcharmodif(hex, fd, maj, ft_getflag(options.flag, '#'));
		ft_addchar(' ', fd, options.width - sizes.len);
	}
	else if (ft_getflag(options.flag, '0'))
	{
		ft_addchar('0', fd, options.width - sizes.len);
		ft_putcharmodif(hex, fd, maj, ft_getflag(options.flag, '#'));
	}
	else if (ft_getflag(options.flag, '0') || options.precision >= 0)
		ft_puthexpadded(hex, sizes.padded, '0', maj);
	else
	{
		ft_addchar(' ', fd, options.width - sizes.len);
		ft_putcharmodif(hex, fd, maj, ft_getflag(options.flag, '#'));
	}
	return (ft_getmax(3, options.width, sizes.len, options.precision));
}
