/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:20:27 by ecunha            #+#    #+#             */
/*   Updated: 2023/12/28 19:33:30 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
}

void	*ft_calloc( size_t elementCount, size_t elementSize )
{
	int		size;
	void	*tab;

	size = elementCount * elementSize;
	if (size > 0 && elementCount > ULONG_MAX / elementSize)
		return (0);
	tab = (void *)malloc(size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, size);
	return (tab);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i > 0)
	{
		if ((char)*s == (char)c)
			return ((char *)s);
		i--;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*dest;
	int		i;
	int		j;

	str1 = (char *)s1;
	str2 = (char *)s2;
	if (!s1)
		return ((char *) s2);
	else if (!s2)
		return ((char *) s1);
	dest = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = -1;
	while (str1[++i])
		dest[i] = str1[i];
	j = -1;
	while (str2[++j])
		dest[i + j] = str2[j];
	dest[i + j] = '\0';
	return (dest);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	if (s1 == NULL || s2 == NULL)
	{
		if (s1 == NULL && s2 == NULL)
			return (0);
		else if (s1 == NULL)
			return (-1);
		else
			return (1);
	}
	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	while (src[len])
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

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

int	match_path_count(char *command, char **path)
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

char	**putlastslash(char **path)
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

char	**pathmaker(char **envp)
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
		if (access(path_temp, X_OK || W_OK || R_OK) == 0)
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

int	child_process(char **argv, char **envp, int *pipefd, t_pipex *files, int comnum)
{
	char	**commande;
	char	**commande_temp;
	char	*path;
	char	**path_list;
	int		id;
	int		i;

	id = fork();
	if (id == 0)
	{
		if (comnum == 1)
			set_fd1(files->fd1, pipefd);
		else if (comnum == 2)
			set_fd2(files->fd2, pipefd);
		i = 0;
		if (argv[comnum + 1][0] == '/')
		{
			commande = ft_split(argv[comnum + 1], ' ');
			path = commande[0];
			commande_temp = remove_path(commande);
			execve(path, commande_temp, envp);
			perror("pipex (command not found) ");
			ft_free(commande);
			exit(EXIT_FAILURE);
		}
		else
		{
			commande = ft_split(argv[comnum + 1], ' ');
			path_list = check_path(envp, commande[0]);
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
	}
	return (id);
}

int	files_open(t_pipex *files, char **argv)
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
		id1 = child_process(argv, envp, pipefd, &files, 1);
	id2 = child_process(argv, envp, pipefd, &files, 2);
	close(pipefd[0]);
	close(pipefd[1]);
	if (files.fd1 != -1)
		waitpid(id1, NULL, 0);
	waitpid(id2, NULL, 0);
	return (0);
}
