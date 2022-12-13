/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:16:54 by ecunha            #+#    #+#             */
/*   Updated: 2022/11/08 17:08:01 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include<stdio.h>
int	ft_strncmp(char *s1, char *s2,size_t n)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n - 1)
	{
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
int main(){

    char str1[40] = "bonjoureqwghgeur";
    char str2[40] = "bonjour";
    printf("---strncmp---\nret:%d\n",strncmp(str1, str2, 7));
	printf("---ft_strncmp---\nret:%d\n",ft_strncmp(str1, str2, 7));
}
