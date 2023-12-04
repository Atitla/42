/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:26:13 by ecunha            #+#    #+#             */
/*   Updated: 2023/12/04 19:42:12 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_three(t_llist **stack_a, t_llist *a_end)
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
		ra(stack_a, a_end);
		ra(stack_a, a_end);
	}
	else if (a < b && b > c && c > a)
	{
		ra(stack_a, a_end);
		sab(stack_a);
		rra(stack_a, a_end);
	}
	else if (a < b && b > c && c < a)
		rra(stack_a, a_end);
	else if (a < b && b > c && c < a)
		sab(stack_a);
	else if (a > b && b < c && c < a)
		ra(stack_a, a_end);
	else if (a > b && b < c && c > a)
		sab(stack_a);
	else if (is_sorted((*stack_a)))
		return ;
	else
		printf("=====bizzare la=====\n");
}
//
//static void	ft_sort_by_smallest(t_llist **stack_a, t_llist **stack_b, \
//			t_ends ends, int size)
//{
//	while (size > 3)
//	{
//		while ((*stack_a)->next->index > 1)
//			ra(stack_a, ends.a_end);
//		pb(stack_a, stack_b, ends.a_end);
//		size--;
//	}
//	ft_sort_three(stack_a, ends.a_end);
//	while (stack_b)
//		pa(stack_a, stack_b, ends.b_end);
//}
//
//static void	ft_sort_by_greatest(t_llist **stack_a, t_llist **stack_b, \
//			t_ends ends, int size)
//{
//	t_llist	*current_a;
//	t_llist	*current_b;
//
//	current_a = (*stack_a)->next ;
//	current_b = (*stack_b)->next ;
//	while (size > 3)
//	{
//		while ((*stack_a)->next->index < size)
//			ra(stack_a, ends.a_end);
//		pb(stack_a, stack_b, ends.a_end);
//		size--;
//	}
//	ft_sort_three(stack_a, ends.a_end);
//	while (current_b != ends.b_end)
//	{
//		pa(stack_a, stack_b, ends.b_end);
//		ra(stack_a, ends.a_end);
//	}
//}
//

static void	ft_sort_four(t_llist **stack_a, t_llist **stack_b, \
			t_ends ends, int size)
{
	t_llist	*current_a;

	current_a = (*stack_a)->next ;
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

static void	ft_sort_five(t_llist **stack_a, t_llist **stack_b, \
			t_ends ends)
{
	t_llist	*current_a;
	int		i;

	i = 1;
	current_a = (*stack_a)->next ;
	if (current_a->index > current_a->next->index &&)
	{
		/* code */
	}

	while (i <= 2)
	{
		while ((*stack_a)->next->index > i)
			ra(stack_a, ends.a_end);
		pb(stack_a, stack_b, ends.a_end);
		i++;
	}
	ft_sort_three(stack_a, ends.a_end);
	while ((*stack_b)->next != ends.b_end)
		pa(stack_a, stack_b, ends.b_end);
}

void	ft_sort(t_llist **stack_a, t_llist **stack_b, t_ends ends, int size)
{
	if (size == 2)
		ra(stack_a, ends.a_end);
	else if (size == 3)
		ft_sort_three(stack_a, ends.a_end);
	else if (size == 4)
		ft_sort_four(stack_a, stack_b, ends, size);
	else if (size == 5)
		ft_sort_five(stack_a, stack_b, ends);
}
