/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:46:41 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/18 13:42:33 by marvin           ###   ########.fr       */
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

void	ft_putcharmodif(unsigned int hex, int fd, int big, enum e_bool modif)
{
	if (modif && hex)
	{
		if (big)
			ft_putstr_fd("0X", fd);
		else
			ft_putstr_fd("0x", fd);
	}
	ft_puthex_fd(hex, fd, big);
}

void	ft_puthexpadded(unsigned int hex, int fd, int count, char c, int big)
{
	ft_addchar(c, fd, count);
	ft_puthex_fd(hex, fd, big);
}

size_t	ft_getsizec(unsigned int hex, struct s_option options)
{
	size_t	len;
	
	if (options.precision < 0)
		len = options.width - ft_countcharhex(hex);
	else {
		len = options.precision - ft_countcharhex(hex);
	}
	return (len);
}

size_t	ft_puthexbroptions_fd(unsigned int hex, int fd, struct s_option options)
{
	int	len;
	int padded;
	enum e_bool maj;

	len = ft_countcharhex(hex) + (ft_getflag(options.flag, '#') && hex) * 2;
	padded = ft_getsizec(hex, options);
	if (options.specifier == 'X')
		maj = TRUE;
	else
		maj = FALSE;
	/*if (!options.width || options.width < len)*/
	/*{*/
	/*	printf("here 1\n");*/
	/*	ft_putcharmodif(hex, fd, maj, ft_getflag(options.flag, '#'));*/
	/*	return (len);*/
	/*}*/
	if (ft_getflag(options.flag, '-'))
	{
		/*printf("here 2\n");*/
		ft_putcharmodif(hex, fd, maj, ft_getflag(options.flag, '#'));
		ft_addchar(' ', fd, options.width - len);
	}
	else if (ft_getflag(options.flag, '0'))
	{
		/*printf("here 3\n");*/
		ft_addchar('0', fd, options.width - len);
		ft_putcharmodif(hex, fd, maj, ft_getflag(options.flag, '#'));
	}
	else if (ft_getflag(options.flag, '0') || options.precision >= 0)
	{
		ft_puthexpadded(hex, fd, padded, '0', maj);
	}
	else
	{
		/*printf("here 4\n");*/
		ft_addchar(' ', fd, options.width - len);
		ft_putcharmodif(hex, fd, maj, ft_getflag(options.flag, '#'));
	}
	return (ft_getmax(3, options.width, len, options.precision));
}
