/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_empty_square.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:05:42 by tgellon           #+#    #+#             */
/*   Updated: 2022/09/11 21:15:54 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include"a.h"

int	first_empty_case(char **tab, int *x, int *y)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i <= 4)
	{
		while (j <= 4)
		{
			if (tab[i][j] == '\0')
			{
				*x = i;
				*y = j;
				return (1);
			}
		}
	}
	return (0);
}