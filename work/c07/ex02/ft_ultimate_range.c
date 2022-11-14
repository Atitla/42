/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:44:35 by ecunha            #+#    #+#             */
/*   Updated: 2022/09/22 19:21:06 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	max -= min;
	*range = malloc(max * sizeof(int));
	if (!*range)
		return (-1);
	i = -1;
	while (++i < max)
		(*range)[i] = min + i;
	return (max);
}
#include <stdio.h>
int main(){
	int **tab = malloc(sizeof(int**));
	int ret = ft_ultimate_range(tab, 10, 20);
	for (int i = 0; i < 10; i++)
		printf("t[%d] = %d\n", i, (*tab)[i]);
	printf("return = %d\n", ret);
	
}