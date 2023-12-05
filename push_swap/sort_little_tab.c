/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:26:13 by ecunha            #+#    #+#             */
/*   Updated: 2023/12/05 10:14:27 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_llist **stack_a, t_llist *a_end)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->next->content;
	b = (*stack_a)->next->next->content;
	c = (*stack_a)->next->next->next->content;
	if (a > b && b > c && c < a)
	{
		sab(stack_a);
		rra(stack_a, a_end);
	}
	else if (a < b && b > c && c > a)
	{
		sab(stack_a);
		ra(stack_a, a_end);
	}
	else if (a < b && b > c && c < a)
		rra(stack_a, a_end);
	else if (a < b && b > c && c < a)
		sab(stack_a);
	else if (a > b && b < c && c < a)
		ra(stack_a, a_end);
	else if (a > b && b < c && c > a)
		sab(stack_a);
}

void	ft_sort_by_greatest(t_llist **stack_a, t_llist **stack_b, \
			t_ends ends, int size)
{
	while (size > 3)
	{
		while ((*stack_a)->next->index < size)
			ra(stack_a, ends.a_end);
		pb(stack_a, stack_b, ends.a_end);
		size--;
	}
	ft_sort_three(stack_a, ends.a_end);
	while ((*stack_b)->next != ends.b_end)
	{
		pa(stack_a, stack_b, ends.b_end);
		ra(stack_a, ends.a_end);
	}
}

void	ft_sort_by_smallest(t_llist **stack_a, t_llist **stack_b, \
			t_ends ends, int size)
{
	int	i;

	i = 1;
	while (size > 3)
	{
		while ((*stack_a)->next->index > i)
			ra(stack_a, ends.a_end);
		pb(stack_a, stack_b, ends.a_end);
		size--;
		i++;
	}
	ft_sort_three(stack_a, ends.a_end);
	while ((*stack_b)->next != ends.b_end)
		pa(stack_a, stack_b, ends.b_end);
}

void	ft_choose_shortest(t_llist **stack_a, t_llist **stack_b, \
			t_ends ends, int size)
{
	int		i;
	t_llist	*current;

	current = (*stack_a)->next;
	i = 0;
	while (current->index < size)
	{
		i++;
		current = current->next;
	}
	if (i < size / 2)
		ft_sort_by_greatest(stack_a, stack_b, ends, size);
	else
		ft_sort_by_smallest(stack_a, stack_b, ends, size);
}

int	is_reverse_sorted(t_llist **stack_a)
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	e;

	a = (*stack_a)->next->index;
	b = (*stack_a)->next->next->index;
	c = (*stack_a)->next->next->next->index;
	d = (*stack_a)->next->next->next->next->index;
	e = (*stack_a)->next->next->next->next->next->index;
	if ((a > b) && (b > c) && (c > d) && (d > e))
		return (1);
	else
		return (0);
}
