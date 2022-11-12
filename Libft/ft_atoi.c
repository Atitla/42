/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:37:57 by ecunha            #+#    #+#             */
/*   Updated: 2022/11/12 12:08:42 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi (char* str){
	int i;
	int number;
	int j;

	i = 0;
	j = 1;
	number = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-'){
		j *= -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - 48);
		i++;
	}
	return (number * j);
	

}
int main(int ac, char **av){

	(void) ac;
	printf("%d\n",atoi(av[1]));
	printf("%d",atoi(av[1]));
}