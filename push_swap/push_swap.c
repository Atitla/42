/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:49:56 by ecunha            #+#    #+#             */
/*   Updated: 2023/11/25 19:00:12 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_int(int n)
{
	printf("%i-> ", n);
}

void	ft_lstadd_front(t_llist **lst, t_llist *new)
{
	t_llist	*temp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	*lst = new;
	new -> next = temp;
}

t_llist	*ft_lstnew(int content)
{
	t_llist	*newlist;

	newlist = malloc(sizeof(t_llist));
	if (!newlist)
		return (NULL);
	newlist -> content = content;
	newlist -> next = NULL;
	return (newlist);
}
void radix_sort(t_llist **stack_a_ptr, t_llist **stack_b_ptr)
{

	int		y;
	while ( >> y != 0)
		y++;

}
void	push_swap(t_llist *lst, void (*f)(int))
{
	printf("stack_a:\n");
	if (!f)
		return ;
	while (lst)
	{
		if (lst->next == NULL)
			break ;
		f(lst->content);
		lst = lst -> next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_llist		*head_a;
	t_llist		*next;
	int			i;

	i = 1;
	if (argc < 2)
		return (0);
	head_a = (t_llist *)malloc(sizeof(t_llist));
	head_a->next = NULL;
	if (head_a == NULL)
		return (0);
	while (i < argc)
	{
		ft_lstadd_front(&head_a, ft_lstnew(atoi(argv[argc - i])));
		i++;
	}
	push_swap(head_a, print_int);
	while (i > 0)
	{
		next = head_a->next;
		free(head_a);
		head_a = next;
		i--;
	}
	return (0);
}
