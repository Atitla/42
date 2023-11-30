/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:28:52 by ecunha            #+#    #+#             */
/*   Updated: 2023/11/30 01:08:27 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexer(t_llist **stack_a_head, t_llist *end, t_llist *copy)
{
	int		i;
	t_llist	*stack_a;
	t_llist *current;

	i = 1;
	stack_a = (*stack_a_head);
	stack_a = stack_a->next;
	while (stack_a != end)
	{
		current = copy->next;
		i = 1;
		while (current != NULL)
		{
			if (current->content == stack_a->content)
			{
				stack_a->index = i;
				break;
			}
			current = current->next;
			i++;
		}
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

void free_llist(t_llist *head)
{
	t_llist *next;

	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
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
	while (is_sorted(current) == 1 || (i < max_index && current != end))
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
	indexer(stack_a_head, end, copy);
	free_llist(copy);
}

void	radix_sort(t_llist **stack_a_ptr, t_llist **stack_b_ptr, t_llist *a_end, t_llist *b_end, int max_index)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (max_index >> i != 0)
		i++;
	while (i > j)
	{
		printf("i = %i\n", i);
		printf("j = %i\n", j);
		k = 0;
		while (k < max_index)
		{
			if (((*stack_a_ptr)->next->index >> k & 1) == 1)
			{
				printf("avant pb :\n");
				push_swap((*stack_a_ptr), print_int);
				printf("!!!!!!!!!!!!!!!!!!!!!\n");
				push_swap((*stack_b_ptr), print_int);
				pb(stack_a_ptr, stack_b_ptr, a_end);
				printf("apres pb :\n");
				push_swap((*stack_a_ptr), print_int);
				printf("!!!!!!!!!!!!!!!!!!!!!\n");
				push_swap((*stack_b_ptr), print_int);

			}
			else
				{
				printf("avant ra :\n");
				push_swap((*stack_a_ptr), print_int);
				ra(stack_a_ptr, a_end);
				printf("apres ra :\n");
				push_swap((*stack_a_ptr), print_int);
				}
			k++;
		}
		while ((*stack_b_ptr)->next != b_end)
		{
			printf("avant pa ------------:\n");
			push_swap((*stack_b_ptr), print_int);
			pa(stack_a_ptr, stack_b_ptr, a_end);
			printf("apres pa ------------:\n");
			push_swap((*stack_b_ptr), print_int);
		}
		j++;
	}
}

