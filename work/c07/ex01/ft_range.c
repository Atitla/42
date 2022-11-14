/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:30:42 by ecunha            #+#    #+#             */
/*   Updated: 2022/09/22 19:23:26 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
		return (NULL);
	max -= min;
	tab = malloc(max * sizeof(int));
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < max)
		tab[i] = min + i;
	return (tab);
}
