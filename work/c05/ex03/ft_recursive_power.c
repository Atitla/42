/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:59:22 by ecunha            #+#    #+#             */
/*   Updated: 2022/09/21 15:28:44 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else if (power % 2 == 0)
		return (ft_recursive_power(nb * nb, power / 2));
	else
		return (nb * ft_recursive_power(nb * nb, (power - 1) / 2));
}
