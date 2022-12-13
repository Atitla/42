/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:54:08 by ecunha            #+#    #+#             */
/*   Updated: 2022/12/13 02:30:17 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int ft_print()
{
	if (format[i] == 'c')
		write(1, format[i], 1);
	else if (format[i] == 's')
		ft_putstr(va_arg(ap, ))
	else if (format[i] == 'p')
		/* code */
	else if (format[i] == 'd')
		/* code */
	else if (format[i] == 'i')
		/* code */
	else if (format[i] == 'u')
		/* code */
	else if (format[i] == 'x')
		/* code */
	else if (format[i] == 'X')
		/* code */
	else if (format[i] == '%')
		/* code */
/*
• %c Affiche un seul caractère.
• %s Affiche une chaîne de caractères (telle que définie par la convention C).
• %p L’argument de pointeur void * doit être affiché en hexadécimal.
• %d Affiche un nombre décimal (base 10).
• %i Affiche un entier en base 10.
• %u Affiche un nombre décimal non signé (base 10).
• %x Affiche un nombre en hexadécimal (base 16) avec des lettres minuscules.
• %X Affiche un nombre en hexadécimal (base 16) avec des lettres majuscules.
• %% Affiche un signe pourcentage.
*/
}

int	ft_count(char *str)
{
	int	count;
	int	i;

	while (str[i])
	{
		if (str[i] == '%')
		{
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	int				elem_count;
	long int		i;
	int 			print_lenght;

	elem_count = ft_count(format);
	va_start(ap, elem_count);
	while (format[i])
	{
		if ((char)format[i] != '%')
		{
			ft_putchar(format[i]);
			print_lenght++;
		}
		else
		{
			i++;
			ft_print(format + i, )
		}
		i++;
	}
	va_end(ap);
}
