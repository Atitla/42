/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:28:52 by ecunha            #+#    #+#             */
/*   Updated: 2023/11/27 23:20:40 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexer(t_llist **stack_a_head, t_llist *end)
{
	int		i;
	t_llist	*stack_a;

	i = 1;
	stack_a = (*stack_a_head);
	while (stack_a->next != end)
	{
		stack_a->index = i;
		i++;
		stack_a = stack_a->next;
	}
}

t_llist	*copy_list(t_llist *head, t_llist *end)
{
	t_llist	*current;
	t_llist	*new_head;
	t_llist	*new_node;
	t_llist *next;

	current = head->next;
	new_head = init_stack(0,0);
	while (current != end)
	{
		new_node = ft_lstnew(current->content);
		if (!new_node)
		{
			while (new_head != NULL)
			{
			next = new_head->next;
			free(new_head);
			new_head = next;
			return NULL;
			}
		}
		ft_lstadd_front(&new_head, new_node);
		current = current->next;
	}
	return new_head;
}


void	swap_nodes(t_llist *current)
{
	int	temp;

	if (current != NULL && current->next != NULL)
	{
		temp = current->content;
		current->content = current->next->content;
		current->next->content = temp;
	}
}

int	is_sorted(t_llist *stack_a)
{
	t_llist	*temp;

	temp = stack_a;
	while (temp->next != NULL)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	bubble_sort(t_llist **stack_a_head, int max_index, t_llist *end)
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
		if (is_sorted(current) == 1)
			break ;
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
	indexer(stack_a_head, end);
	//free_llist();
	push_swap(copy->next, print_int);
	push_swap2(copy->next, print_int);
}
/*
void	radix_sort(t_llist **stack_a_ptr, t_llist *end, int max_index)
{
	int	i;
	int	j;
	int	k;

	while (max_index >> i != 0)
		i++;
	while (i > j)
	{
		k = 0;
		while (k < max_index)
		{
			if (((*stack_a_ptr)->index >> z & 1) == 1)
				pb(stack_a_ptr);
			else
				ra(stack_a_ptr);
			k++;
		}
		while ()
		{
		}
	}
}
*/
