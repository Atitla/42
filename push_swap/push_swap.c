/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:49:56 by ecunha            #+#    #+#             */
/*   Updated: 2023/12/02 16:18:49 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(int *argc, char ***argv)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	if ((*argc) == 2)
		(*argv) = ft_split((*argv)[1], ' ');
	(*argc) = (get_len_char(argv));
	i = 0;
	while (i < *argc)
	{
		j = i + 1;
		while (j < *argc)
		{
			if (ft_strcmp((*argv)[i], (*argv)[j]) == 0)
				return (ft_error());
			j++;
		}
		i++;
	}
	if (is_only_num((*argv)) == 0)
		return (ft_error());
	return (0);
}

void	ft_lstadd_front(t_llist **lst, t_llist *new)
{
	t_llist	*temp;

	if (!new || !(*lst))
		return ;
	if ((*lst)->next == NULL)
	{
		(*lst)->next = new;
		return ;
	}
	temp = (*lst)->next;
	(*lst)->next = new;
	new -> next = temp;
}

t_llist	*ft_lstnew(int content, int *boo)
{
	t_llist	*newlist;

	if (*boo != 0)
		return (NULL);
	newlist = malloc(sizeof(t_llist));
	if (!newlist)
		return (NULL);
	newlist -> content = content;
	newlist -> index = 0;
	newlist -> next = NULL;
	return (newlist);
}

t_llist	*init_stack(int argc, char **argv)
{
	t_llist		*head;
	t_llist		*end;
	int			i;
	int			boo;

	boo = 0;
	head = ft_assign(&end);
	if (head == NULL)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (boo != 0)
			return (free_llist (head), NULL);
		ft_lstadd_front(&head, ft_lstnew(ft_atoi(argv[argc - i], &boo), &boo));
		i++;
	}
	return (head);
}

int	main(int argc, char **argv)
{
	t_llist		*stack_a_head;
	t_llist		*a_end;
	t_llist		*stack_b_head;
	t_llist		*b_end;

	if (check_args(&argc, &argv) != 0)
		return (0);
	stack_b_head = init_stack(0, 0);
	stack_a_head = init_stack(argc, argv);
	if (stack_a_head == NULL || stack_b_head == NULL)
		return (free_llist(stack_b_head), 0);
	a_end = stack_a_head;
	while (a_end->next != NULL)
		a_end = a_end->next;
	b_end = stack_b_head;
	while (b_end->next != NULL)
		b_end = b_end->next;
	if (bubble_sort(&stack_a_head, argc - 1, a_end) == 1)
		return (free_llist(stack_a_head), free_llist(stack_b_head), 0);
	//if ((argc - 1) >= 3 && (argc - 1) <= 5)
	//	ft_sort_liltab(&stack_a_head, &stack_b_head, a_end, argc - 1);
	//else
	radix_sort(&stack_a_head, &stack_b_head, a_end, argc - 1);
	return (free_llist (stack_a_head), free_llist (stack_b_head), 0);
}
