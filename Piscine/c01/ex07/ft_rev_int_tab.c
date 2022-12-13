/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:27:19 by ecunha            #+#    #+#             */
/*   Updated: 2022/09/20 18:06:35 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	i;

	i = 0;
	while (i < (size / 2))
	{
		temp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = temp;
		i++;
	}
}
#include <stdio.h>
int main()
{
	const int TAILLE = 1;
	int t[TAILLE] = {1,2,3};
	for ( int i = 0; i < TAILLE ; i++ )
		printf("t[%d]=%d\n",i,t[i]);
	ft_rev_int_tab(t, TAILLE);
	printf("\nTableau inversé\n\n");
	for ( int i = 0; i < TAILLE ; i++ )
		printf("t[%d]=%d\n",i,t[i]);
}