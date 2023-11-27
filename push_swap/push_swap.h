/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:52:06 by ecunha            #+#    #+#             */
/*   Updated: 2023/11/27 22:41:59 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

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

#endif
