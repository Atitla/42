/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:27:31 by ecunha            #+#    #+#             */
/*   Updated: 2024/01/04 20:15:21 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct t_pipex
{
	int	fd1;
	int	fd2;
}	t_pipex;

char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(const char *str, char c);
int		ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strdup(const char *src);
char	**check_path(char **envp, char *command);

char	**ft_free(char **array);
int		set_fd1(t_pipex *files, int *pipefd);
int		set_fd2(t_pipex *files, int *pipefd);
void	close_fds(t_pipex files);
int		child_process1(char **argv, char **envp, int *pipefd, t_pipex *files);
int		child_process2(char **argv, char **envp, int *pipefd, t_pipex *files);

#endif
