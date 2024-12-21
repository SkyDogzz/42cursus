/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:19:20 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/21 14:02:52 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../include/stack.h"

t_bool	parse_arg(t_stack *stack, int argc, char *argv[]);
t_bool	check_stack(t_stack *stack, int argc, char *argv[]);

#endif
