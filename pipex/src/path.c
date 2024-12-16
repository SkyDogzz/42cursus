/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 23:13:30 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/16 23:13:31 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

char	*construct_full_path(char *path, char *cmd)
{
	char	*full_path;
	size_t	path_len;
	size_t	cmd_len;

	path_len = ft_strlen(path);
	cmd_len = ft_strlen(cmd);
	full_path = malloc(path_len + 1 + cmd_len + 1);
	if (!full_path)
		return (NULL);
	ft_strlcpy(full_path, path, path_len + 1);
	ft_strlcat(full_path, "/", path_len + 2);
	ft_strlcat(full_path, cmd, path_len + cmd_len + 2);
	return (full_path);
}

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*full_path;
	int		i;

	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (!*envp)
		return (NULL);
	paths = ft_split(*envp + 5, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = construct_full_path(paths[i], cmd);
		if (!full_path || access(full_path, X_OK) == 0)
			return (free_paths(paths), full_path);
		free(full_path);
		i++;
	}
	return (free_paths(paths), NULL);
}
