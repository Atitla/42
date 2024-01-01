/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:27:31 by ecunha            #+#    #+#             */
/*   Updated: 2024/01/01 15:03:00 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <sys/wait.h>

typedef struct t_pipex
{
	int	fd1;
	int	fd2;
}	t_pipex;

char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(const char *str, char c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strdup(const char *src);
char	**check_path(char **envp, char *command);
char	**remove_path(char **commande);

char	**ft_free(char **array);
void	set_fd1(int fd_stdin, int *pipefd);
void	set_fd2(int fd_stdout, int *pipefd);
int		child_process1(char **argv, char **envp, int *pipefd, t_pipex *files);
int		child_process2(char **argv, char **envp, int *pipefd, t_pipex *files);

#endif
