/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:51:34 by tgellon           #+#    #+#             */
/*   Updated: 2022/09/12 11:29:10 by ecunha           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "a.h"

int	main(int argc, char **argv)
{
	int		i;
	char	**tab;

	i = 0;
	if (ft_check_argc(argc))
		write(1, "Error\n", 6);
	else if (ft_check_argv(**argv))
		write(1, "Error\n, 6");
	else
	{
		tab = (char**)malloc(sizeof(char*) * 6);
		while (i < 6)
		{
			tab[i] = (char*)malloc(sizeof(char) * 6);
			i++;
		}
		ft_pov_init(**tab, argv[1]);
		if (ft_check_lines(**tab, x, y))
			write(1, "Error\n, 6");
		else
		{
			ft_solve(**tab);
			ft_row_column(**tab, x, y);
		}
			ft_print_tab(**tab);
		free(tab);
	}
}

