/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:50:52 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 17:58:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	ft_putstr_fd_options(char *s, int fd, struct s_option options)
{
	int	len;

	len = ft_strlen(s);
	if (!options.width)
	{
		ft_putstr_fd(s, fd);
		return ;
	}
	if (ft_getflag(options.flag, '-'))
	{
		ft_putstr_fd(s, fd);
		ft_addchar(options.width - len, ' ', fd);
	}
	else if (ft_getflag(options.flag, '0') && !options.precision)
	{
		ft_addchar(options.width - len, ' ', fd);
		ft_putstr_fd(s, fd);
	}
	else
	{
		ft_addchar(options.width - len, ' ', fd);
		ft_putstr_fd(s, fd);
	}
}
