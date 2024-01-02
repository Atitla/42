/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:49:16 by ecunha            #+#    #+#             */
/*   Updated: 2024/01/02 14:27:21 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**remove_path(char **commande)
{
	char	*last_slash;

	last_slash = ft_strrchr(commande[0], '/');
	if (last_slash != NULL)
	{
		commande[0] = last_slash + 1;
	}
	return (commande);
}

static int	match_path_count(char *command, char **path)
{
	int		i;
	int		j;
	char	*path_temp;

	i = 0;
	j = 0;
	while (path[i])
	{
		path_temp = ft_strjoin(path[i], command);
		if (access(path_temp, X_OK) == 0)
			j++;
		i++;
		free(path_temp);
	}
	return (j);
}

static char	**putlastslash(char **path)
{
	int		i;
	char	**path_temp;

	i = 0;
	while (path[i])
		i++;
	path_temp = malloc(sizeof(char *) * (i + 1));
	path_temp[0] = NULL;
	i = 0;
	while (path[i])
	{
		path_temp[i] = ft_strjoin(path[i], "/");
		i++;
	}
	if (path_temp[0] == NULL)
	{
		path_temp[0] = ft_strdup("/usr/bin/");
		path_temp[1] = NULL;
	}
	else
		path_temp[i] = NULL;
	return (path_temp);
}

static char	**pathmaker(char **envp)
{
	char	**path;
	char	**path_temp;
	int		i;

	if (envp[0] == NULL)
	{
		path = malloc(sizeof(char *) * 2);
		path[0] = ft_strdup("/usr/bin/");
		path[1] = NULL;
		return (path);
	}
	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	path_temp = ft_split((envp[i] + 5), ':');
	path = putlastslash(path_temp);
	ft_free(path_temp);
	return (path);
}

char	**check_path(char **envp, char *command)
{
	char	**path;
	char	**match_path;
	char	*path_temp;
	int		i;
	int		j;

	path = pathmaker(envp);
	match_path = malloc(sizeof(char *) * (match_path_count(command, path) + 1));
	i = 0;
	j = 0;
	while (path[i])
	{
		path_temp = ft_strjoin(path[i], command);
		if (access(path_temp, X_OK) == 0)
		{
			match_path[j] = ft_strdup(path_temp);
			j++;
		}
		i++;
		free(path_temp);
	}
	match_path[j] = NULL;
	ft_free(path);
	return (match_path);
}
