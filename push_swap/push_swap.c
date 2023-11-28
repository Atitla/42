/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:49:56 by ecunha            #+#    #+#             */
/*   Updated: 2023/11/28 13:48:02 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_int(int n)
{
	printf("%i->", n);
}

int	check_args(int argc, char **argv)
{
	int i;
	int	j;

	i = 0;
	while(i < argc)
	{
		j = i + 1;
		while(j < argc)
		{
			if(ft_strcmp(argv[i], argv[j]) == 0)
				return(1);
			j++;
		}
		i++;
	}
	return(0);
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


t_llist	*ft_lstnew(int content)
{
	t_llist	*newlist;

	newlist = malloc(sizeof(t_llist));
	if (!newlist)
		return (NULL);
	newlist -> content = content;
	newlist -> index = 0;
	newlist -> next = NULL;
	return (newlist);
}

void	push_swap(t_llist *lst, void (*f)(int))
{
	printf("stack_a:\n");
	if (!f)
		return ;
	while (lst)
	{
		if (lst->next == NULL)
		{
			printf("%i", lst->content);
			printf("nill");
			break ;
		}
		f(lst->content);
		lst = lst -> next;
	}
	printf("\n");
}

void	push_swap2(t_llist *lst, void (*f)(int))
{
	printf("index a:\n");
	if (!f)
		return ;
	while (lst)
	{
		if (lst->next == NULL)
		{
			printf("%i", lst->content);
			printf("nill");
			break ;
		}
		f(lst->index);
		lst = lst -> next;
	}
	printf("\n");
}

t_llist	*init_stack(int argc, char **argv)
{
	t_llist		*head;
	t_llist		*end;
	int			i;

	head = (t_llist *)malloc(sizeof(t_llist));
	end = (t_llist *)malloc(sizeof(t_llist));
	if (head == NULL || end == NULL)
		return (NULL);
	head->content = 0;
	head->next = end;
	head->index = 0;
	end->content = 0;
	end->next = NULL;
	end->index = 0;
	i = 1;
	while (i < argc)
	{
		ft_lstadd_front(&head, ft_lstnew(atoi(argv[argc - i])));
		i++;
	}
	return head;
}

int	main(int argc, char **argv)
{
	t_llist		*stack_a_head;
	t_llist		*end;
	t_llist		*next;
	//t_llist		*stack_b_head;

	if (argc < 2)
		return (0);
	check_args(argc, argv);
	stack_a_head = init_stack(argc, argv);
	if (stack_a_head == NULL)
		return (0);
	end = stack_a_head;
	while (end->next != NULL)
		end = end->next;
	push_swap(stack_a_head->next, print_int);
	bubble_sort(&stack_a_head, argc - 1, end);
	push_swap(stack_a_head->next, print_int);
	push_swap2(stack_a_head, print_int);
	while (stack_a_head != end)
	{
		next = stack_a_head->next;
		free(stack_a_head);
		stack_a_head = next;
	}
	free(end);
	return (0);
}
