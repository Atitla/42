/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:20:27 by ecunha            #+#    #+#             */
/*   Updated: 2024/01/04 20:07:06 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	err_cmd_not_found(int comnum)
{
	if (comnum == 1)
		write(2, "pipex 1 : command not found\n", 28);
	else
		write(2, "pipex 2 : command not found\n", 28);
}

static void	command_exec_relative(char **argv, char **envp, int comnum)
{
	char	**commande;
	char	*path;
	int		i;

	i = 0;
	while (argv[comnum + 1][i] && argv[comnum + 1][i] == ' ')
		i++;
	if (!argv[comnum + 1][i])
		return (err_cmd_not_found(comnum));
	commande = ft_split(argv[comnum + 1], ' ');
	if (!commande)
		return ;
	path = commande[0];
	execve(path, commande, envp);
	err_cmd_not_found(comnum);
	ft_free(commande);
}

static void	command_exec_nopath(char **argv, char **envp, int comnum)
{
	char	**commande;
	char	**path_list;
	int		i;

	i = 0;
	while (argv[comnum + 1][i] && argv[comnum + 1][i] == ' ')
		i++;
	if (!argv[comnum + 1][i])
		return (err_cmd_not_found(comnum));
	commande = ft_split(argv[comnum + 1], ' ');
	if (!commande)
		return ;
	path_list = check_path(envp, commande[0]);
	if (!path_list)
	{
		ft_free(commande);
		return (err_cmd_not_found(comnum));
	}
	i = 0;
	while (path_list[i])
		execve(path_list[i++], commande, envp);
	err_cmd_not_found(comnum);
	ft_free(commande);
	ft_free(path_list);
}

int	child_process1(char **argv, char **envp, int *pipefd, t_pipex *files)
{
	int	id;

	id = fork();
	if (id == 0)
	{
		if (set_fd1(files, pipefd) == -1)
			return (-1);
		if (argv[2][0] == '/')
		{
			command_exec_relative(argv, envp, 1);
			close(1);
			close(0);
			exit(EXIT_FAILURE);
		}
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
	int	id;

	id = fork();
	if (id == 0)
	{
		if (set_fd2(files, pipefd) == -1)
			return (-1);
		if (argv[3][0] == '/')
		{
			command_exec_relative(argv, envp, 2);
			close(1);
			close(0);
			exit(EXIT_FAILURE);
		}
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
