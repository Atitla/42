/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:49:56 by ecunha            #+#    #+#             */
/*   Updated: 2023/11/22 16:25:54 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_int_array stack_a)
{
	size_t	i;

	i = 0;
	printf("stack_a:\n");
	while (i < stack_a.size)
	{
		printf("%d\n", stack_a.array[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_int_array	stack_a;
	int			i;

	i = 0;
	if (argc < 2)
		return (0);
	stack_a.array = malloc(sizeof(int) * argc);
	stack_a.size = argc - 1;
	if (stack_a.array == NULL)
	{
		return (0);
	}
	i = 1;
	while (argv[i])
	{
		stack_a.array[i - 1] = atoi(argv[i]);
		i++;
	}
	push_swap(stack_a);
	free(stack_a.array);
	return (0);
}
