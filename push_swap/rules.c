/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:10:06 by ecunha            #+#    #+#             */
/*   Updated: 2023/11/29 18:51:41 by ecunha           ###   ########.fr       */
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

void	ss(t_llist **stack_a_ptr, t_llist **stack_b_ptr)
{
	sab(stack_a_ptr);
	sab(stack_b_ptr);
}

void	pb(t_llist **stack_a_ptr, t_llist **stack_b_ptr, t_llist *a_end, t_llist *b_end)
{
	t_llist	*tempa;
	t_llist	*tempb;

	if (*stack_a_ptr == NULL || (*stack_a_ptr)->next == a_end)
		return ;
	if ((*stack_a_ptr)->next->next != NULL)
		tempa = (*stack_a_ptr)->next->next;
	else
		tempa = (*stack_a_ptr)->next;
	if ((*stack_b_ptr)->next == b_end)
		tempb = (*stack_b_ptr)->next;
	else
		tempb = (*stack_b_ptr)->next->next;
	(*stack_b_ptr)->next = (*stack_a_ptr)->next;
	(*stack_a_ptr)->next = tempa;
	(*stack_b_ptr)->next->next = tempb;

}

void	pb(t_llist **stack_a_ptr, t_llist **stack_b_ptr, t_llist *a_end, t_llist *b_end)
{
	t_llist	*tempa;
	t_llist	*tempb;
	t_llist	*buf;

	buf = NULL;
	if (*stack_a_ptr == NULL || (*stack_a_ptr)->next == a_end)
		return ;
	tempa = (*stack_a_ptr)->next->next;
	if ((*stack_b_ptr)->next == b_end)
		tempb = (*stack_b_ptr)->next;
	else
	{
		buf = (*stack_b_ptr)->next;
		tempb = (*stack_b_ptr)->next->next;
	}
	(*stack_b_ptr)->next = (*stack_a_ptr)->next;
	if (buf)
	{
		(*stack_b_ptr)->next->next = buf;
		(*stack_b_ptr)->next->next->next = tempb;

	}
	(*stack_a_ptr)->next = tempa;

}

void	pa(t_llist **stack_a_ptr, t_llist **stack_b_ptr, t_llist *a_end, t_llist *b_end)
{
	t_llist	*tempb;
	t_llist	*tempa;

	if (*stack_b_ptr == NULL || (*stack_b_ptr)->next == b_end)
		return ;
	if ((*stack_b_ptr)->next->next != NULL)
		tempb = (*stack_b_ptr)->next->next;
	else
		tempb = (*stack_b_ptr)->next;
	if ((*stack_a_ptr)->next == a_end)
		tempa = (*stack_a_ptr)->next;
	else
		tempa = (*stack_a_ptr)->next->next;
	(*stack_a_ptr)->next = (*stack_b_ptr)->next;
	(*stack_b_ptr)->next = tempb;
	(*stack_a_ptr)->next->next = tempa;

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

}
