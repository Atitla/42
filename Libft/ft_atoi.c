/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:37:57 by ecunha            #+#    #+#             */
/*   Updated: 2022/11/16 03:31:49 by ecunha           ###   ########.fr       */
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
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - 48);
		i++;
	}
	return (number * j);
	

}
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static void			 ft_print_result2(char c)
{
		write(1, &c, 1);
}

static void			 ft_print_result(int n)
{
		if (n >= 0)
		{
				if (n >= 10)
						ft_print_result(n / 10);
				ft_print_result2(n % 10 + '0');
		}
		else
		{
				ft_print_result2('-');
				if (n <= -10)
						ft_print_result(n / -10);
				ft_print_result2(n % -10 * -1 + '0');
		}
}

int							  main(int argc, const char *argv[])
{
		int			 arg;

		alarm(5);
		if (argc == 1)
				return (0);
		else if ((arg = atoi(argv[1])) == 1)
				ft_print_result(ft_atoi("0"));
		else if (arg == 2)
				ft_print_result(ft_atoi("546:5"));
		else if (arg == 3)
				ft_print_result(ft_atoi("-4886"));
		else if (arg == 4)
				ft_print_result(ft_atoi("+548"));
		else if (arg == 5)
				ft_print_result(ft_atoi("054854"));
		else if (arg == 6)
				ft_print_result(ft_atoi("000074"));
		else if (arg == 7)
				ft_print_result(ft_atoi("+-54"));
		else if (arg == 8)
				ft_print_result(ft_atoi("-+48"));
		else if (arg == 9)
				ft_print_result(ft_atoi("--47"));
		else if (arg == 10)
				ft_print_result(ft_atoi("++47"));
		else if (arg == 11)
				ft_print_result(ft_atoi("+47+5"));
		else if (arg == 12)
				ft_print_result(ft_atoi("-47-5"));
		else if (arg == 13)
				ft_print_result(ft_atoi("\e475"));
		else if (arg == 14)
				ft_print_result(ft_atoi("\t\n\r\v\f  469 \n"));
		else if (arg == 15)
				ft_print_result(ft_atoi("-2147483648"));
		else if (arg == 16)
				ft_print_result(ft_atoi("2147483647"));
		else if (arg == 17)
				ft_print_result(ft_atoi("\t\n\r\v\fd469 \n"));
		else if (arg == 18)
				ft_print_result(ft_atoi("\n\n\n  -46\b9 \n5d6"));
		else if (arg == 19)
				ft_print_result(ft_atoi(""));
		return (0);
}