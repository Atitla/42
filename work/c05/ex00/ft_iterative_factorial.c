/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:28:10 by ecunha            #+#    #+#             */
/*   Updated: 2022/09/21 15:29:32 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	temp;

	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	temp = nb;
	while (nb-- > 1)
	{
		temp *= nb;
	}
	return (temp);
}
