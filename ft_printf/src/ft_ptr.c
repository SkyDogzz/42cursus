/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:10:21 by marvin            #+#    #+#             */
/*   Updated: 2024/11/14 13:38:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	ft_putptr_fd_options(void *p, int fd, struct s_option options)
{
	if (!options.width)
		ft_putptr_fd(p, fd);
	else if (ft_getflag(options.flag, '-'))
	{
		ft_putptr_fd(p, fd);
		ft_addchar(options.width - 14, ' ', fd);
	}
	else if (ft_getflag(options.flag, '0') && !options.precision)
	{
		ft_addchar(options.width - 14, '0', fd);
		ft_putptr_fd(p, fd);
	}
	else
	{
		ft_addchar(options.width - 14, ' ', fd);
		ft_putptr_fd(p, fd);
	}
}

void	ft_putptr_fd(void *p, int fd)
{
	unsigned long	ptr;
	char			*res;
	int				pos;

	ptr = (unsigned long)&p;
	res = (char *)malloc(sizeof(char) * 15);
	res[0] = '0';
	res[1] = 'x';
	res[14] = 0;
	pos = 13;
	while (pos >= 2)
	{
		if (ptr % 16 <= 9)
			res[pos] = ptr % 16 + '0';
		else
			res[pos] = ptr % 16 + 'a' - 10;
		ptr /= 16;
		pos--;
	}
	ft_putstr_fd(res, fd);
	free(res);
}
