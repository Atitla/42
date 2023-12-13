/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:20:27 by ecunha            #+#    #+#             */
/*   Updated: 2023/12/13 05:16:20 by ecunha           ###   ########.fr       */
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
	if (fd_infile < 0)
	{
		perror("Erreur lors de l'ouverture du fichier d'entrée");
		exit(EXIT_FAILURE);
	}

	fd_outfile = open(argv[3], O_WRONLY | O_CREAT, 0644);
	if (fd_outfile < 0)
	{
		perror("Erreur lors de l'ouverture du fichier de sortie");
		exit(EXIT_FAILURE);
	}
	if (pipe(pipefd) < 0)
	{
		perror("Erreur lors de la creation du pipe");
		exit(EXIT_FAILURE);
	}

	id1 = fork();
	if (id1 < 0)
	{
		perror("Erreur lors de la création du processus enfant");
		exit(EXIT_FAILURE);
	}

	if (id1 == 0)
	{
		if (dup2(fd_infile, STDIN_FILENO) < 0)
		{
			perror("Erreur lors de la redirection de stdin");
			exit(EXIT_FAILURE);
		}
		if (dup2(fd_outfile, STDOUT_FILENO) < 0)
		{
			perror("Erreur lors de la redirection de stdout");
			exit(EXIT_FAILURE);
		}

		close(fd_infile);
		close(fd_outfile);
		char **commande = ft_split(argv[2], ' ');
		path = ft_strjoin("/usr/bin/", commande[0]);
		if (execve(path, commande, envp) < 0)
		{
			perror("Erreur lors de l'exécution de la commande avec execve");
			exit(EXIT_FAILURE);
		}
	}

	id2 = fork();
	if (id2 < 0)
	{
		perror("Erreur lors de la création du processus enfant");
		exit(EXIT_FAILURE);
	}

	if (id2 == 0)
	{
		if (dup2(fd_infile, STDIN_FILENO) < 0)
		{
			perror("Erreur lors de la redirection de stdin");
			exit(EXIT_FAILURE);
		}
		if (dup2(fd_outfile, STDOUT_FILENO) < 0)
		{
			perror("Erreur lors de la redirection de stdout");
			exit(EXIT_FAILURE);
		}

		close(fd_infile);
		close(fd_outfile);
		char **commande = ft_split(argv[2], ' ');
		path = ft_strjoin("/usr/bin/", commande[0]);
		if (execve(path, commande, envp) < 0)
		{
			perror("Erreur lors de l'exécution de la commande avec execve");
			exit(EXIT_FAILURE);
		}
	}
	waitpid(id, NULL, 0);
	return (0);
}
