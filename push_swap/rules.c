/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:10:06 by ecunha            #+#    #+#             */
/*   Updated: 2023/11/30 16:18:47 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
