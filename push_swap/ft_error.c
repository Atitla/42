/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:21:31 by ecunha            #+#    #+#             */
/*   Updated: 2023/12/05 10:10:57 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	write(2, "Error\n", 7);
	return (1);
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

t_llist	*find_end_stack(t_llist *end)
{
	while (end->next != NULL)
		end = end->next;
	return (end);
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

void	ft_free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
