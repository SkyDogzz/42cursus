/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:52:32 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/26 17:31:56 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "../../include/libft.h"
# include "../../include/ft_printf.h"
# include "../../include/get_next_line.h"

typedef struct s_error
{
	int	libft;
	int	ft_printf;
	int	get_next_line;
}	t_error;

int	test_libft(void);
int	test_ftprintf(void);
int	test_getnextline(void);
int test_char(void);

#endif
