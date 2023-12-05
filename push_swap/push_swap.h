/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:52:06 by ecunha            #+#    #+#             */
/*   Updated: 2023/12/05 14:43:23 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct t_llist {
	int				content;
	int				index;
	struct t_llist	*next;
}	t_llist;

typedef struct t_ends {
	struct t_llist	*a_end;
	struct t_llist	*b_end;
}	t_ends;

t_llist				*ft_lstnew(int content, int *boo);
t_llist				*init_stack(int argc, char **argv);
t_llist				*ft_assign(t_llist **end);
t_llist				*copy_list(t_llist *head, t_llist *end);
t_llist				*free_llist(t_llist *head);
t_llist				*find_end_stack(t_llist *end);
void				ft_lstadd_front(t_llist **lst, t_llist *new);
int					ft_error(void);
int					bubble_sort(t_llist **stack_a_ptr, int max_index, \
					char **argv, t_llist *end);
void				radix_sort(t_llist **stack_a_ptr, t_llist **stack_b_ptr, \
					t_llist *a_end, int max_index);
void				ft_sort(t_llist **stack_a, t_llist **stack_b, \
					t_ends ends, int size);
void				ft_sort_three(t_llist **stack_a, t_llist *a_end);
int					is_sorted(t_llist *stack_a);
int					indexer(t_llist **stack_a_head, t_llist *end, \
					char **argv, t_llist *copy);
void				swap_nodes(t_llist *current);
void				pb(t_llist **stack_a_ptr, t_llist **stack_b_ptr, \
					t_llist *a_end);
void				pa(t_llist **stack_a_ptr, t_llist **stack_b_ptr, \
					t_llist *b_end);
void				ra(t_llist **stack_a_ptr, t_llist *a_end);
void				rra(t_llist **stack_a_ptr, t_llist *a_end);
void				sab(t_llist **stack_a_ptr);
int					is_only_num(char **argv);
int					ft_cmpint(int *argc, char ***argv);
int					get_len_char(char ***str);
void				ft_free_tab(char **tab);
char				**ft_split(const char *str, char c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_atoi(const char *str, int *boo);
int					ft_isdigit(int c);
void				ft_choose_shortest(t_llist **stack_a, t_llist **stack_b, \
					t_ends ends, int size);
int					ft_printf(const char *format, ...);
int					ft_putcharcount(int nbr, int lgt);
int					ft_putnbr(int nb);
int					ft_putunbr(unsigned int nb);
int					ft_putstr(char *str);
int					ft_putptr(void *ptr);
int					ft_puthexa(unsigned long nbr, int upper);

#endif
