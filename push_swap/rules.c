/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:10:06 by ecunha            #+#    #+#             */
/*   Updated: 2023/11/25 14:37:02 by ecunha           ###   ########.fr       */
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

void	pab(t_llist **stack_a_ptr, t_llist **stack_b_ptr)
{
	if (stack_a_ptr == NULL || stack_b_ptr == NULL)
		return ;

}
