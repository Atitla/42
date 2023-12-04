/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:26:13 by ecunha            #+#    #+#             */
/*   Updated: 2023/12/04 13:31:22 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_llist	*biggest_index(t_llist *stack, t_llist *end)
{
	int		index_max;
	t_llist	*current;

	current = stack->next;
	index_max = 0;
	while (current->next != end)
	{
		if (current->index > index_max)
			index_max = current->index;
		current = current->next;
	}
	return (current);
}

t_llist	*smallest_index(t_llist *stack, t_llist *end)
{
	int		index_min;
	t_llist	*current;

	current = stack->next;
	index_min = 0;
	while (current->next != end)
	{
		if (current->index < index_min)
			index_min = current->index;
		current = current->next;
	}
	return (current);
}

static void	ft_sort_by_smallest(t_llist *stack_a, t_llist *stack_b, \
			t_ends ends, int size)
{
	while (size > 3)
	{
		while ((stack_a)->index > smallest_index(stack_a, ends.a_end)->index)
			ra(stack_a, ends.a_end);
		pb(stack_a, stack_b, ends.a_end);
		size--;
	}
	ft_sort_three(stack_a);
	while (stack_b)
		pa(stack_a, stack_b, ends.b_end);
}

static void	ft_sort_by_greatest(t_llist *stack_a, t_llist *stack_b, \
			t_ends ends, int size)
{
	while (size > 3)
	{
		while ((stack_a)->index < biggest_index(stack_a, ends.a_end)->index)
			ra(stack_a, ends.a_end);
		pb(stack_a, stack_b, ends.a_end);
		size--;
	}
	ft_sort_three(stack_a);
	while (stack_b)
	{
		pa(stack_a, stack_b, ends.b_end);
		ra(stack_a, ends.a_end);
	}
}

void	ft_sort_three(t_llist *stack_a, t_llist *a_end)
{

}

static void	ft_choose_shortest(t_llist *stack_a, t_llist *stack_b, \
			t_ends ends, int size)
{
	int		index;
	int		index_max;
	t_llist	*current;

	current = stack_a->next;
	index = 0;
	while (current->index < biggest_index(stack_a, ends.a_end)->index)
	{
		index++;
		current = current->next;
	}
	if (index < size / 2)
		ft_sort_by_greatest(stack_a, stack_b, ends, size);
	else
		ft_sort_by_smallest(stack_a, stack_b, ends, size);
}

void	ft_sort(t_llist *stack_a, t_llist *stack_b, t_ends ends, int size)
{
	if (is_sorted(stack_a))
		return ;
	if (size == 2)
		ra(stack_a, ends.a_end);
	else if (size == 3)
		ft_sort_three(stack_a, ends.a_end);
	else
		ft_choose_shortest(stack_a, stack_b, ends, size);
}
