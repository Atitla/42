/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:59:38 by tgellon           #+#    #+#             */
/*   Updated: 2022/09/12 11:30:46 by ecunha           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "a.h"

void	ft_pov_init(char **tab, char *str)
{
	int	tabpos;
	int	strpos;

	strpos = 0;
	tabpos = 1;
	while (strpos <= 30)
	{
		if (strpos <= 6)
			tab[0][tabpos] = str[strpos];
		else if (strpos <= 14)
			tab[5][tabpos] = str[strpos];
		else if (strpos <= 22)
			tab[tabpos][0] = str[strpos];
		else if (strpos <= 30)
			tab[strpos][5] = str[strpos];
		tabpos ++;
		if (tabpos > 4)
			tabpos = 1;
		strpos += 2;
	}
}
