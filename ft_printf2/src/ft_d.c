/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:26:07 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/20 17:58:43 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_countdichar(int d)
{
	int	len;

	if (d == 0)
		return (1);
	len = 0;
	if (d < 0)
		len++;
	while (d)
	{
		d /= 10;
		len++;
	}
	return (len);
}

static void	ft_putdioptions(int d, int fd, int count, int plus, int space)
{
	if (d < 0)
	{
		count++;
		ft_putchar_fd('-', fd);
	}
	if (d >= 0 && plus)
	{
		count++;
		ft_putchar_fd('+', fd);
	}
	if (d >= 0 && space)
	{
		count++;
		ft_putchar_fd(' ', fd);
	}
	while (count-- > 0)
		ft_putchar_fd('0', fd);
	if (d < 0)
	{
		if (d == -2147483648)
		{
			ft_putchar_fd('2', fd);
			ft_putnbr_fd(147483648, fd);
		}
		else
			ft_putnbr_fd(-d, fd);
	}
	else
		ft_putnbr_fd(d, fd);
	(void) count;
}

int	ft_putdioptions_fd(int d, struct s_option options, int fd)
{
	struct s_carac caracs;

	ft_initcaracs(&caracs);
	caracs.size = ft_countdichar(d);
	caracs.pad = options.width - caracs.size;
	caracs.padLeft = options.minus;
	if (caracs.padLeft)
	{	
		ft_putdioptions(d, fd, options.precision - caracs.size, options.plus, options.space);
		ft_addchar(caracs.pad, options.zero);
	}
	else
	{	
		ft_addchar(caracs.pad, options.zero);
		ft_putdioptions(d, fd, options.precision - caracs.size, options.plus, options.space);
	}
	return (ft_getmax(3, caracs.size, options.width, options.precision + (1 && d < 0))
	 + (options.plus && d >= 0) + (options.space && d >= 0));
}
