/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:17:38 by ecunha            #+#    #+#             */
/*   Updated: 2022/09/15 17:52:02 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    printf("strncmp:%d",strncmp(argv[1],argv[2],atoi(argv[3])));
    printf("\nft_strncmp:%d",ft_strncmp(argv[1],argv[2],atoi(argv[3])));
}