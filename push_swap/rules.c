/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:10:06 by ecunha            #+#    #+#             */
/*   Updated: 2023/12/02 17:16:01 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sab(t_llist **stack_a_ptr)
{
	t_llist	*first;
	t_llist	*second;
	t_llist	*stack_aob;

	if (stack_a_ptr == NULL)
		return ;
	stack_aob = *stack_a_ptr;
	if (stack_aob == NULL || stack_aob->next == NULL)
		return ;
	first = stack_aob;
	second = stack_aob->next;
	first->next = second->next;
	second->next = first;
	*stack_a_ptr = second;
}

void	pb(t_llist **stack_a_ptr, t_llist **stack_b_ptr, t_llist *a_end)
{
	t_llist	*tempa;
	t_llist	*node_to_move;

	if (*stack_a_ptr == NULL || (*stack_a_ptr)->next == a_end)
		return ;
	node_to_move = (*stack_a_ptr)->next;
	if (node_to_move->next != NULL)
		tempa = node_to_move->next;
	else
		tempa = node_to_move;
	(*stack_a_ptr)->next = tempa;
	node_to_move->next = (*stack_b_ptr)->next;
	(*stack_b_ptr)->next = node_to_move;
	printf("pb\n");
}

void	pa(t_llist **stack_a_ptr, t_llist **stack_b_ptr, t_llist *b_end)
{
	t_llist	*tempb;
	t_llist	*node_to_move;

	if (*stack_b_ptr == NULL || (*stack_b_ptr)->next == b_end)
		return ;
	node_to_move = (*stack_b_ptr)->next;
	if (node_to_move->next != NULL)
		tempb = node_to_move->next;
	else
		tempb = node_to_move;
	(*stack_b_ptr)->next = tempb;
	node_to_move->next = (*stack_a_ptr)->next;
	(*stack_a_ptr)->next = node_to_move;
	printf("pa\n");
}

void	ra(t_llist **stack_a_ptr, t_llist *a_end)
{
	t_llist	*temp;
	t_llist	*stack_a_lastelem;

	if (*stack_a_ptr == NULL || a_end == NULL)
		return ;
	if ((*stack_a_ptr)->next == NULL || a_end->next != NULL)
		return ;
	stack_a_lastelem = (*stack_a_ptr);
	while (stack_a_lastelem->next != a_end)
		stack_a_lastelem = stack_a_lastelem->next;
	temp = (*stack_a_ptr)->next->next;
	(*stack_a_ptr)->next->next = a_end;
	stack_a_lastelem->next = (*stack_a_ptr)->next;
	(*stack_a_ptr)->next = temp;
	printf("ra\n");
}

void	rra(t_llist **stack_a_ptr, t_llist *a_end)
{
	t_llist	*temp;
	t_llist	*stack_a_lastelem;

	if (*stack_a_ptr == NULL || a_end == NULL)
		return ;
	if ((*stack_a_ptr)->next == NULL || a_end->next != NULL)
		return ;
	stack_a_lastelem = (*stack_a_ptr);
	while (stack_a_lastelem->next->next != a_end)
		stack_a_lastelem = stack_a_lastelem->next;
	temp = (*stack_a_ptr)->next;
	(*stack_a_ptr)->next->next = a_end;
	stack_a_lastelem->next = (*stack_a_ptr)->next;
	(*stack_a_ptr)->next = temp;
	printf("ra\n");
}

int	bubble_sort(t_llist **stack_a_head, int max_index, t_llist *end)
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
	if (indexer(stack_a_head, end, copy) == 1)
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
