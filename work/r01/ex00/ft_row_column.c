/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_row_column.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:49:34 by dbaule            #+#    #+#             */
/*   Updated: 2022/09/11 20:44:26 by dbaule           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include"a.h"

int	ft_row_column(char **tab, int x, int y)
{
	char	i;
	int		j;

	x = 1;
	y = 1;
	j = 1;
	while (tab[x][y] && (x < 5 || y < 5))
	{		
		while (tab[x][y] && (x < 5 || y < 5))
		{
			while (tab[x][y] && ((j + x) < 5) \
				|| (j + y) < 5)
			{
				i = tab[x][y];
				if (tab[x + j][y] == i)
					return (0);
				if (tab[x][y + j] == i)
					return (0);
				j++;
			}
			j = 1;
			y++;
		}
		y = 1;
		x++;
	}
	return (1);
}
