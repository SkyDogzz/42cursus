/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_refill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:00:00 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/25 16:14:06 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	refill_map(t_wrapper *wrapper)
{
	int	fd;

	fd = open(wrapper->map->filename, O_RDONLY);
	if (fd < 0)
		exit_msg_code("File not opened\n", 1);
	fill_map(wrapper->map, fd);
	close(fd);
}
