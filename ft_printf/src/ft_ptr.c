/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:10:21 by marvin            #+#    #+#             */
/*   Updated: 2024/11/14 17:30:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_countcharp(unsigned long p)
{
	int	len;

	if (p == 0)
		return (1);
	len = 0;
	while (p)
	{
		p /= 16;
		len++;
	}
	return (len);
}

int	ft_putptr_fd_options(void *p, int fd, struct s_option options)
{
	int	len;

	if ((unsigned long)p == 0)
	{
		ft_putstr_fd("(nil)", fd);
		return (5);
	}
	len = ft_countcharp((unsigned long)p) + 2;
	ft_putstr_fd("0x", fd);
	if (!options.width)
		ft_putptr_fd(p, fd);
	else if (ft_getflag(options.flag, '-'))
	{
	ft_putptr_fd(p, fd);
	ft_addchar(options.width - len, ' ', fd);
}
	else if (ft_getflag(options.flag, '0') && !options.precision)
	{
		ft_addchar(options.width - len, '0', fd);
		ft_putptr_fd(p, fd);
	}
	else
{
		ft_addchar(options.width - len, ' ', fd);
		ft_putptr_fd(p, fd);
	}
	if (options.width > len)
		return (options.width);
	return (len);
}

void	ft_putptr_fd(void *p, int fd)
{
	unsigned long	ptr;
	char			num;

	ptr = (unsigned long)p;
	if ((void *) (ptr / 16) != 0)
		ft_putptr_fd((void *) (ptr / 16), fd);
	if (ptr % 16 <= 9)
		num = (ptr % 16) + '0';
	else
		num = (ptr % 16) + 'a' - 10;
	write(fd, &num, 1);
}
