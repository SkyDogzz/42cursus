/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xX.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:09:32 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/21 00:38:23 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_countxchar(unsigned int x)
{
	int	len;

	if (x == 0)
		return (1);
	len = 0;
	while (x > 0)
	{
		x /= 16;
		len++;
	}
	return (len);
}

void	ft_putxnbr_fd(unsigned int x, int maj, int fd)
{
	char	letter;

	if (x / 16 > 0)
		ft_putxnbr_fd(x / 16, maj, fd);
	if (x % 16 <= 9)
		letter = x % 16 + '0';
	else
		letter = x % 16 + (maj ? 'A' : 'a') - 10;
	write(fd, &letter, 1);
}

int	ft_putxoptions_fd(unsigned int x, struct s_option options, int fd)
{
	struct s_carac	caracs;
	int				maj;

	ft_initcaracs(&caracs);
	caracs.size = (x == 0 && options.precision == 0) ? 0 : ft_countxchar(x);
	caracs.pad = options.width - ft_getmax(2, caracs.size, options.precision)
		- ((options.sharp && x != 0) ? 2 : 0);
	caracs.pad = (caracs.pad < 0) ? 0 : caracs.pad;
	caracs.padleft = options.minus;
	maj = (options.specifier == 'X');

	// Remplissage à gauche
	if (!caracs.padleft && (!options.zero || options.precision >= 0))
		ft_addchar(caracs.pad, 0);

	// Préfixe pour le sharp
	if (options.sharp && x != 0)
		ft_putstr_fd(maj ? "0X" : "0x", fd);

	// Remplissage de précision
	if (options.precision > caracs.size)
		ft_addchar(options.precision - caracs.size, 1);

	// Remplissage avec zéro pour le flag `0` uniquement si pas de précision
	if (!caracs.padleft && options.zero && options.precision < 0)
		ft_addchar(caracs.pad, 1);

	// Affichage du nombre, sauf si taille = 0 et précision explicitement définie comme 0
	if (caracs.size > 0)
		ft_putxnbr_fd(x, maj, fd);

	// Remplissage à droite
	if (caracs.padleft)
		ft_addchar(caracs.pad, 0);

	return (ft_getmax(3, caracs.size, options.width, options.precision)
		+ ((options.sharp && x != 0) ? 2 : 0));
}
