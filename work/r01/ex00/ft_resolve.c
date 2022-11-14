/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:04:47 by tgellon           #+#    #+#             */
/*   Updated: 2022/09/12 11:32:14 by ecunha           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include"a.h"

int	ft_solve(char **tab)
{
	if (game_over(tab))
		return (ft_row_column(**tab, x, y));
	else
	{
		int	x;
		int	y;
		int	i;
		int	*px = &x;
		int	*py = &y;

		i = 0;
		first_empty_case(**tab, x, y);
		while (++i < 4)
		{
			input_number(*px, *py, i);
			if (ft_solve(tab))
				return (1);
		}
		void_case(x, y);
	}
	return (0);
}
