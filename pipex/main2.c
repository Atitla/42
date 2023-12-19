/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:20:27 by ecunha            #+#    #+#             */
/*   Updated: 2023/12/14 01:13:20 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	dest = malloc ((strlen(s1) + strlen(s2) + 1) * sizeof(char));
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

int	main(int argc, char **argv, char **envp)
{
	int		fd_infile;
	int		fd_outfile;
	int		id1;
	int		id2;
	char	*path;
	int		pipefd[2];
	(void)argc;

	fd_infile = open(argv[1], O_RDONLY);

	fd_outfile = open(argv[4], O_WRONLY | O_CREAT, 0644);

	pipe(pipefd);
	id1 = fork();

	if (id1 == 0)
	{
		dup2(fd_infile, STDIN_FILENO);
		dup2(pipefd[0], STDOUT_FILENO);

		close(fd_infile);
		close(pipefd[0]);
		char **commande = ft_split(argv[2], ' ');
		path = ft_strjoin("/usr/bin/", commande[0]);
		execve(path, commande, envp);
	}
	id2 = fork();
	if (id2 == 0)
	{
		dup2(pipefd[1], STDIN_FILENO);
		dup2(fd_outfile, STDOUT_FILENO);

		close(pipefd[1]);
		close(fd_outfile);
		char **commande = ft_split(argv[2], ' ');
		path = ft_strjoin("/usr/bin/", commande[0]);
		execve(path, commande, envp);
	}
	waitpid(id1, NULL, 0);
	waitpid(id2, NULL, 0);
	return (0);
}
