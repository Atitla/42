/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:09:08 by ecunha            #+#    #+#             */
/*   Updated: 2023/12/05 13:41:34 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_llist **stack_a, t_llist **stack_b, t_ends ends, int size)
{
	if (size == 2)
		ra(stack_a, ends.a_end);
	else if (size == 3)
		ft_sort_three(stack_a, ends.a_end);
	else
		ft_choose_shortest(stack_a, stack_b, ends, size);
}

int	bubble_sort(t_llist **stack_a_head, int max_index, \
	char **argv, t_llist *end)
{
	int		i;
	int		j;
	t_llist	*current;
	t_llist	*copy;

	i = 0;
	copy = copy_list((*stack_a_head), end);
	current = copy->next;
	while (i < max_index && current != end)
	{
		current = copy->next;
		j = 0;
		while (j < (max_index - i - 1))
		{
			if (current->next->content < current->content)
				swap_nodes(current);
			current = current->next;
			j++;
		}
		i++;
	}
	if (indexer(stack_a_head, end, argv, copy) == 1)
		return (free_llist(copy), 1);
	free_llist(copy);
	return (0);
}

void	radix_sort(t_llist **stack_a_ptr, t_llist **stack_b_ptr, \
		t_llist *a_end, int max_index)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (max_index >> i != 0)
		i++;
	while (i >= j)
	{
		k = 0;
		while (k < max_index)
		{
			if (((*stack_a_ptr)->next->index >> j & 1) == 0)
				pb(stack_a_ptr, stack_b_ptr, a_end);
			else
				ra(stack_a_ptr, a_end);
			k++;
		}
		while ((*stack_b_ptr)->next->next != NULL)
			pa(stack_a_ptr, stack_b_ptr, a_end);
		j++;
		if (is_sorted(*stack_a_ptr))
			return ;
	}
}

int	is_only_num(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) != 1 && argv[i][j] != '-')
				return (0);
			else if (argv[i][j] == '-' && argv[i][j + 1] == '-')
				return (0);
			j++;
		}
		if (argv[i][j - 1] == '-')
			return (0);
		i++;
	}
	return (1);
}

int	ft_cmpint(int *argc, char ***argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < *argc)
	{
		j = i + 1;
		while (j < *argc)
		{
			if (ft_strcmp((*argv)[i], (*argv)[j]) == 0)
			{
				if (ft_strcmp((*argv)[0], "push_swap") == 0)
					ft_free_tab((*argv));
				return (ft_error());
			}
			j++;
		}
		i++;
	}
	return (0);
}
