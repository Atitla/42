/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:20:27 by ecunha            #+#    #+#             */
/*   Updated: 2024/01/04 16:20:30 by ecunha           ###   ########.fr       */
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
	if (comnum == 1)
		write(2, "pipex : command 1 not found\n", 28);
	else
		write(2, "pipex : command 2 not found\n", 28);
	ft_free(commande);
}

static void	command_exec_nopath(char **argv, char **envp, int comnum)
{
	char	**commande;
	char	**path_list;
	int		i;

	commande = ft_split(argv[comnum + 1], ' ');
	if(!commande)
		return;
	path_list = check_path(envp, commande[0]);
	if(!path_list)
		return;
	i = 0;
	while (path_list[i])
	{
		execve(path_list[i], commande, envp);
		i++;
	}
	if (comnum == 1)
		write(2, "pipex 1 : command not found\n", 28);
	else
		write(2, "pipex 2 : command not found\n", 28);
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
		set_fd1(files, pipefd);
		if (argv[2][0] == '/')
			command_exec_relative(argv, envp, 1);
		else
		{
			command_exec_nopath(argv, envp, 1);
			close(1);
			close(0);
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
		set_fd2(files, pipefd);
		if (argv[3][0] == '/')
			command_exec_relative(argv, envp, 2);
		else
		{
			command_exec_nopath(argv, envp, 2);
			close(1);
			close(0);
			exit(EXIT_FAILURE);
		}
	}
	return (id);
}
