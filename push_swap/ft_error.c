/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:21:31 by ecunha            #+#    #+#             */
/*   Updated: 2023/12/02 17:31:13 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	write(2, "Error\n", 7);
	return (1);
}

void	print_llist_data(t_llist *head)
{
	t_llist	*current;

	current = head;
	while (current != NULL)
	{
		printf("Content: %d\n", current->content);
		printf("Index: %d\n", current->index);
		current = current->next;
	}
}

t_llist	*ft_assign(t_llist **end)
{
	t_llist	*head;

	head = (t_llist *)malloc(sizeof(t_llist));
	*end = (t_llist *)malloc(sizeof(t_llist));
	if (!head || !end)
		return (NULL);
	head->content = 0;
	head->next = (*end);
	head->index = 0;
	(*end)->content = 0;
	(*end)->next = NULL;
	(*end)->index = 0;
	return (head);
}

int	get_len_char(char ***str)
{
	int		i;
	char	**temp;

	temp = *str;
	i = 0;
	while (temp[i])
		i++;
	return (i);
}

int	is_only_num(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) != 1 && argv[i][j] != '-')
				return (0);
			else if (argv[i][j] == '-' && argv[i][j + 1] == '-')
				return (0);
			j++;
		}
		if (argv[i][j - 1] == '-')
			return 0;
		i++;
	}
	return (1);
}

//void	ft_sort_liltab(t_llist **stack_a_head, t_llist **stack_b_head,
//		*a_end, int argc)
//{
//
//}


