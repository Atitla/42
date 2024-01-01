/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:20:27 by ecunha            #+#    #+#             */
/*   Updated: 2024/01/01 14:58:44 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	command_exec_relative(char **argv, char **envp, int comnum)
{
	char	**commande;
	char	**commande_temp;
	char	*path;

	commande = ft_split(argv[comnum + 1], ' ');
	path = commande[0];
	commande_temp = remove_path(commande);
	execve(path, commande_temp, envp);
	perror("pipex (command not found) ");
	ft_free(commande);
	exit(EXIT_FAILURE);
}

static void	command_exec_nopath(char **argv, char **envp, int comnum)
{
	char	**commande;
	char	**path_list;
	int		i;

	commande = ft_split(argv[comnum + 1], ' ');
	path_list = check_path(envp, commande[0]);
	i = 0;
	while (path_list[i])
	{
		execve(path_list[i], commande, envp);
		i++;
	}
	perror("pipex (command not found) ");
	ft_free(commande);
	ft_free(path_list);
	exit(EXIT_FAILURE);
}

int	child_process1(char **argv, char **envp, int *pipefd, t_pipex *files)
{
	int		id;

	id = fork();
	if (id == 0)
	{
		set_fd1(files->fd1, pipefd);
		if (argv[2][0] == '/')
		{
			command_exec_relative(argv, envp, 1);
			exit(EXIT_FAILURE);
		}
		else
		{
			command_exec_nopath(argv, envp, 1);
			exit(EXIT_FAILURE);
		}
	}
	return (id);
}

int	child_process2(char **argv, char **envp, int *pipefd, t_pipex *files)
{
	int		id;

	id = fork();
	if (id == 0)
	{
		set_fd2(files->fd2, pipefd);
		if (argv[3][0] == '/')
		{
			command_exec_relative(argv, envp, 2);
			exit(EXIT_FAILURE);
		}
		else
		{
			command_exec_nopath(argv, envp, 2);
			exit(EXIT_FAILURE);
		}
	}
	return (id);
}
