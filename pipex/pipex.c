/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:20:27 by ecunha            #+#    #+#             */
/*   Updated: 2023/12/18 17:35:43 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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
	unsigned int	i;

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
	str[i] = 0;
	return (str);
}

int range_to_comm(char *commande)
{
	int	i;
	int	j;

	i = ft_strlen(commande);
	while(commande[i] != '/')
		j++;
	return (j);
}

int	match_path_count(char *command, char **path)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (path[i])
	{
		if(access(ft_strjoin(path[i], command), X_OK) == 0)
			j++;
		i++;
	}
	return (j);
}

char **check_path(char **envp, char *command)
{
	char	**path;
	char	**match_path;
	int		i;
	int		j;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	path = ft_split((envp[i] + 5), ':');
	match_path = malloc(sizeof(char *) * (match_path_count(command, path) + 1));
	i = 0;
	j = 0;
	while(path[i])
	{
		ft_strjoin(path[i], "/");
		if(access(ft_strjoin(path[i], command), X_OK) == 0)
		{
			match_path[j] = ft_strdup(ft_strjoin(path[i], command));
			j++;
		}
		i++;
	}
	match_path[j] = NULL;
	return (match_path);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_infile;
	int		fd_outfile;
	int		id1;
	int		id2;
	char	*path;
	char	**path_list;
	int		pipefd[2];
	char **commande = NULL;
	int		i = 0;
	int		pathlenght;

	if (argc < 4 || !argv[4])
		return (1);
	fd_infile = open(argv[1], O_RDONLY);
	fd_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_outfile == -1)
		return (1);
	pipe(pipefd);
	id1 = fork();
	if (id1 == 0)
	{
		dup2(fd_infile, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);

		close(fd_infile);
		close(pipefd[1]);
		close(pipefd[0]);
		commande = ft_split(argv[2], ' ');
		path = ft_strjoin("/usr/bin/", commande[0]);
		execve(path, commande, envp);
		ft_free(commande);
		free(path);
		exit(EXIT_FAILURE);
	}
	id2 = fork();
	if (id2 == 0)
	{

		dup2(pipefd[0], STDIN_FILENO);
		dup2(fd_outfile, STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		close(fd_outfile);
		if (argv[3][0] == '/')
		{
			commande = ft_split(argv[3], ' ');
			path = commande[0];
			pathlenght = range_to_comm(commande[0]);
			execve(path, commande + pathlenght, envp);
			ft_free(commande);
			free(path);
		}
		else
		{
			commande = ft_split(argv[3], ' ');
			path_list = check_path(envp, commande[0]);
			while (path_list[i])
			{
				execve(path_list[i], commande, envp);
				i++;
			}
			ft_free(commande);
			ft_free(path_list);
		}
		exit(EXIT_FAILURE);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(id1, NULL, 0);
	waitpid(id2, NULL, 0);

	//ft_free(commande);
	//main return 1 si un execve fail
	return (0);
}
