/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:57:33 by ecunha            #+#    #+#             */
/*   Updated: 2022/11/17 01:09:22 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
static int	ft_abs(int nbr)
=======
<<<<<<< HEAD
static int	ft_abs(int nbr)
=======
static int
	ft_abs(int nbr)
>>>>>>> 7c9e364ff28836393573e8fa9c5a0cb1b6caa36c
>>>>>>> b765d704b96b4bf0cc8772c85fef3374f8613245
{
	return ((nbr < 0) ? -nbr : nbr);
}

<<<<<<< HEAD
static void	ft_strrev(char *str)
=======
<<<<<<< HEAD
static void	ft_strrev(char *str)
=======
static void
	ft_strrev(char *str)
>>>>>>> 7c9e364ff28836393573e8fa9c5a0cb1b6caa36c
>>>>>>> b765d704b96b4bf0cc8772c85fef3374f8613245
{
	size_t	length;
	size_t	i;
	char	tmp;

	length = ft_strlen(str);
	i = 0;
	while (i < length / 2)
	{
		tmp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = tmp;
		i++;
	}
}

<<<<<<< HEAD
char	*ft_itoa(int n)
=======
ùgitchar	*ft_itoa(int n)
>>>>>>> b765d704b96b4bf0cc8772c85fef3374f8613245
{
	char	*str;
	int		is_neg;
	size_t	length;

	is_neg = (n < 0);
	if (!(str = ft_calloc(11 + is_neg, sizeof(*str))))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	length = 0;
	while (n != 0)
	{
		str[length++] = '0' + ft_abs(n % 10);
		n = (n / 10);
	}
	if (is_neg)
		str[length] = '-';
	ft_strrev(str);
	return (str);
}
