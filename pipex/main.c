#include <stdio.h>

void check_args(void)
{
	if (argv[2][0] == '/')
		{
			commande = ft_split(argv[2], ' ');
			path = commande[0];
			commande_temp = remove_path(commande);
			execve(path, commande_temp, envp);
			perror("pipex : command not found\n");
			ft_free(commande);
		}
	else
		{
			commande = ft_split(argv[2], ' ');
			path_list = check_path(envp, commande[0]);
			while (path_list[i])
			{
				execve(path_list[i], commande, envp);
				i++;
			}
			perror("pipex : command not found\n");
			ft_free(commande);
			ft_free(path_list);
		}
	if (argv[3][0] == '/')
		{
			commande = ft_split(argv[3], ' ');
			path = commande[0];
			commande_temp = remove_path(commande);
			execve(path, commande_temp, envp);
			perror("pipex : command not found\n");
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
			perror("pipex : command not found\n");
			ft_free(commande);
			ft_free(path_list);
		}
}

int	main(int argc, char **argv, char **envp)
{

	if (argc != 5)
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	check_args();
	//exec_command();

	return (0);
}
