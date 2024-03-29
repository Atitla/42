/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:28:52 by ecunha            #+#    #+#             */
/*   Updated: 2023/12/05 13:44:22 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	indexer(t_llist **stack_a_head, t_llist *end, char **argv, t_llist *copy)
{
	int		i;
	t_llist	*stack_a;
	t_llist	*current;

	i = 1;
	stack_a = (*stack_a_head)->next;
	while (stack_a != end)
	{
		current = copy->next;
		i = 1;
		while (current != NULL)
		{
			if (current->content == stack_a->content)
			{
				stack_a->index = i;
				break ;
			}
			current = current->next;
			i++;
		}
		stack_a = stack_a->next;
	}
	if (is_sorted((*stack_a_head)) == 1 && ft_strcmp(argv[0], "push_swap") == 0)
		return (ft_free_tab(argv), is_sorted((*stack_a_head)));
	return (is_sorted((*stack_a_head)));
}

t_llist	*copy_list(t_llist *head, t_llist *end)
{
	t_llist	*current;
	t_llist	*new_head;
	t_llist	*new_node;
	int		i;

	current = head->next;
	new_head = init_stack(0, 0);
	i = 0;
	while (current != end)
	{
		new_node = ft_lstnew(current->content, &i);
		if (!new_node)
			free_llist(new_head);
		ft_lstadd_front(&new_head, new_node);
		current = current->next;
	}
	return (new_head);
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
	while (temp->next->index != 0)
	{
		if (temp->index > temp->next->index)
		{
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}

t_llist	*free_llist(t_llist *head)
{
	t_llist	*next;

	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
	return (NULL);
}
