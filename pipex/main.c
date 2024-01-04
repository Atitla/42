/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:50:23 by ecunha            #+#    #+#             */
/*   Updated: 2024/01/04 14:13:26 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_fd1(t_pipex *files, int *pipefd)
{
	dup2(files->fd1, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(files->fd1);
	if (files->fd2 != -1)
		close(files->fd2);
	close(pipefd[1]);
	close(pipefd[0]);
}

void	set_fd2(t_pipex *files, int *pipefd)
{
	dup2(pipefd[0], STDIN_FILENO);
	dup2(files->fd2, STDOUT_FILENO);
	if (files->fd1 != -1)
		close(files->fd1);
	close(files->fd2);
	close(pipefd[0]);
	close(pipefd[1]);
}

static int	files_open(t_pipex *files, char **argv)
{
	files->fd1 = open(argv[1], O_RDONLY);
	files->fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (files->fd1 == -1)
	{
		perror("pipex infile ");
		if (files->fd2 == -1)
			return (perror("pipex outfile "), 1);
	}
	else if (files->fd2 == -1)
		return (perror("pipex outfile "), 2);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	files;
	int		id1;
	int		id2;
	int		pipefd[2];

	if (argc != 5 || ft_strncmp(argv[1], "\0", 1) == 0 || ft_strncmp(argv[2], "\0", 1) == 0  || ft_strncmp(argv[3], "\0", 1) == 0 || ft_strncmp(argv[4], "\0", 1) == 0 )
		return (write(1, "pipex : wrong input in arguments\0", 33), 1);
	if (files_open(&files, argv) == 1)
		return (1);
	pipe(pipefd);
	if (files.fd1 != -1)
		id1 = child_process1(argv, envp, pipefd, &files);
	if (files.fd2 != -1)
		id2 = child_process2(argv, envp, pipefd, &files);
	close(pipefd[0]);
	close(pipefd[1]);
	if (files.fd1 != -1)
		waitpid(id1, NULL, 0);
	if (files.fd2 != -1)
		waitpid(id2, NULL, 0);
	if (files.fd1 != -1)
		close(files.fd1);
	if (files.fd2 != -1)
		close(files.fd2);
	return (0);
}
