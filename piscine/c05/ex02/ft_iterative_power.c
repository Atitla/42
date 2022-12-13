/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:14:21 by ecunha            #+#    #+#             */
/*   Updated: 2022/09/21 15:28:38 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	nb_temp;

	i = 1;
	nb_temp = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (++i <= power)
		nb_temp *= nb;
	return (nb_temp);
}
