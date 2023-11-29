/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:52:06 by ecunha            #+#    #+#             */
/*   Updated: 2023/11/29 17:51:14 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libftmax/libft.h"
typedef struct t_llist {
	int				content;
	int				index;
	struct t_llist	*next;
}	t_llist;

void				bubble_sort(t_llist **stack_a_ptr, int max_index, t_llist *end);
int					is_sorted(t_llist *stack_a);
void				swap_nodes(t_llist *current);
void				push_swap(t_llist *lst, void (*f)(int));
t_llist				*ft_lstnew(int content);
void				ft_lstadd_front(t_llist **lst, t_llist *new);
void				print_int(int n);
t_llist				*init_stack(int argc, char **argv);
void				push_swap2(t_llist *lst, void (*f)(int));
void				indexer(t_llist **stack_a_head, t_llist *end, t_llist *copy);
void				free_llist(t_llist *head);
void				radix_sort(t_llist **stack_a_ptr, t_llist **stack_b_ptr, t_llist *a_end, t_llist *b_end, int max_index);
void				pb(t_llist **stack_a_ptr, t_llist **stack_b_ptr, t_llist *a_end, t_llist *b_end);
void				pa(t_llist **stack_a_ptr, t_llist **stack_b_ptr, t_llist *a_end, t_llist *b_end);
void				ra(t_llist **stack_a_ptr, t_llist *a_end);

#endif
