/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:55:14 by ecunha            #+#    #+#             */
/*   Updated: 2022/09/20 14:53:14 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int	is_in_base(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	pos_in_tab(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c)
		i++;
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	else
	{
		while (base[i])
		{
			j = i + 1;
			while (base[j])
			{
				if (base[i] == base[j] || (base[i] == '-' || base[i] == '+'))
				{
					return (0);
					j++;
				}
				j++;
			}
			i++;
		}
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	j;
	int	number;

	i = 0;
	j = 1;
	number = 0;
	if (check_base(base) != 1)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	while (str[i])
	{
		if (is_in_base(base, str[i]) != 1)
			return (0);
		number = (number * ft_strlen(base)) + pos_in_tab(base, str[i]);
		i++;
	}
	return (number * j);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	(void) argc;
	printf("%i\n", ft_atoi_base(argv[1], argv[2]));
}