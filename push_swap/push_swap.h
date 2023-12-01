/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:52:06 by ecunha            #+#    #+#             */
/*   Updated: 2023/12/01 17:14:16 by ecunha           ###   ########.fr       */
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

t_llist				*ft_lstnew(int content);
t_llist				*init_stack(int argc, char **argv);
t_llist				*copy_list(t_llist *head, t_llist *end);
void				ft_lstadd_front(t_llist **lst, t_llist *new);
t_llist				*free_llist(t_llist *head);
int					ft_error();
int					bubble_sort(t_llist **stack_a_ptr, int max_index, \
					t_llist *end);
void				radix_sort(t_llist **stack_a_ptr, t_llist **stack_b_ptr, \
					t_llist *a_end, int max_index);
int					is_sorted(t_llist *stack_a);
int					indexer(t_llist **stack_a_head, t_llist *end, \
					t_llist *copy);
void				swap_nodes(t_llist *current);
void				pb(t_llist **stack_a_ptr, t_llist **stack_b_ptr, \
					t_llist *a_end);
void				pa(t_llist **stack_a_ptr, t_llist **stack_b_ptr, \
					t_llist *b_end);
void				ra(t_llist **stack_a_ptr, t_llist *a_end);
int					is_only_num(char **argv);

#endif
