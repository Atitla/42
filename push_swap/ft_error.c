/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:21:31 by ecunha            #+#    #+#             */
/*   Updated: 2023/12/01 18:17:43 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_error()
{
	write(2, "Error\n", 7);
	return (1);
}

int is_only_num(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) != 1)
				{write(2, "p\n", 2);
				return (0);}
			j++;
		}
		i++;
	}
	return (1);
}

//void	ft_sort_liltab(t_llist **stack_a_head, t_llist **stack_b_head, t_llist *a_end, int argc)
//{
//
//}
