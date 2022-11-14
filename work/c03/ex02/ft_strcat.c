/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:14:13 by ecunha            #+#    #+#             */
/*   Updated: 2022/09/14 16:15:40 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i ++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	lenght;

	i = 0;
	lenght = ft_strlen(dest);
	while (src[i])
	{
		dest[lenght + i] = src[i];
		i++;
	}
	dest[lenght + i] = '\0';
	return (dest);
}
