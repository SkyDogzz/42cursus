/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 23:15:10 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/23 16:22:04 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	add_char_to_arg(char **arg, size_t *arg_len, char c)
{
	char	*new_arg;

	new_arg = ft_realloc(*arg, (*arg_len + 1) * sizeof(char),
			(*arg_len + 2) * sizeof(char));
	if (!new_arg)
	{
		free(*arg);
		perror("realloc");
		exit(EXIT_FAILURE);
	}
	new_arg[*arg_len] = c;
	new_arg[*arg_len + 1] = '\0';
	*arg_len += 1;
	*arg = new_arg;
}

void	add_arg_to_list(char ***args, int *count, char *arg)
{
	char	**new_args;

	new_args = ft_realloc(*args, (*count + 1) * sizeof(char *),
			(*count + 2) * sizeof(char *));
	if (!new_args)
	{
		perror("realloc");
		exit(EXIT_FAILURE);
	}
	new_args[*count] = arg;
	new_args[*count + 1] = NULL;
	*count += 1;
	*args = new_args;
}

void	handle_quoted_char(t_parser *parser)
{
	if (parser->in_single_quote && parser->c == '\'')
		parser->in_single_quote = 0;
	else if (parser->in_double_quote && parser->c == '"')
		parser->in_double_quote = 0;
	else
		add_char_to_arg(&parser->current_arg, &parser->arg_len, parser->c);
}

void	handle_unquoted_char(t_parser *parser)
{
	if (parser->c == '\'')
		parser->in_single_quote = 1;
	else if (parser->c == '"')
		parser->in_double_quote = 1;
	else if (parser->c == ' ' || parser->c == '\t')
	{
		if (parser->current_arg)
		{
			add_arg_to_list(&parser->args, &parser->arg_count,
				parser->current_arg);
			parser->current_arg = NULL;
			parser->arg_len = 0;
		}
	}
	else
		add_char_to_arg(&parser->current_arg, &parser->arg_len, parser->c);
}

char	**parse_args(const char *cmd_line)
{
	t_parser	parser;
	size_t		i;

	i = 0;
	parser = (t_parser){0};
	while (cmd_line[i] != '\0')
	{
		parser.c = cmd_line[i];
		if (parser.in_single_quote || parser.in_double_quote)
			handle_quoted_char(&parser);
		else
			handle_unquoted_char(&parser);
		i++;
	}
	if (parser.current_arg)
		add_arg_to_list(&parser.args, &parser.arg_count, parser.current_arg);
	if (!parser.args)
		return (calloc(1, sizeof(char *)));
	return (parser.args);
}
