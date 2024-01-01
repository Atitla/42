/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:50:23 by ecunha            #+#    #+#             */
/*   Updated: 2024/01/01 14:58:58 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_fd1(int fd_stdin, int *pipefd)
{
	dup2(fd_stdin, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(fd_stdin);
	close(pipefd[1]);
	close(pipefd[0]);
}

void	set_fd2(int fd_stdout, int *pipefd)
{
	dup2(pipefd[0], STDIN_FILENO);
	dup2(fd_stdout, STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd_stdout);
}

static int	files_open(t_pipex *files, char **argv)
{
	files->fd1 = open(argv[1], O_RDONLY);
	if (files->fd1 == -1)
		perror("pipex ");
	files->fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (files->fd2 == -1)
		return (perror("pipex "), 1);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	files;
	int		id1;
	int		id2;
	int		pipefd[2];

	if (argc != 5 || !argv[4])
		return (1);
	if (files_open(&files, argv) == 1)
		return (1);
	pipe(pipefd);
	if (files.fd1 != -1)
		id1 = child_process1(argv, envp, pipefd, &files);
	id2 = child_process2(argv, envp, pipefd, &files);
	close(pipefd[0]);
	close(pipefd[1]);
	if (files.fd1 != -1)
		waitpid(id1, NULL, 0);
	waitpid(id2, NULL, 0);
	return (0);
}
