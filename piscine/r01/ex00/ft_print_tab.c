/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:43:13 by tgellon           #+#    #+#             */
/*   Updated: 2022/09/11 20:07:09 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include"a.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= 5)
	{
		j = 0;
		while (j <= 5)
		{
			ft_putchar(tab[i][j]);
			j++;
			if (j == 5)
				ft_putchar('\n');
		}
		i++;
	}
}
