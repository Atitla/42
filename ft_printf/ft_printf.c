/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:54:08 by ecunha            #+#    #+#             */
/*   Updated: 2022/12/13 04:37:21 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	ft_print(va_list ap, char format, int print_lenght)
{
	if (format == 'c')
		ft_putcharcount(va_arg(ap, int), &print_lenght);
	else if (format == 's')
		ft_putstr(va_arg(ap, int));
	else if (format == 'p')
		ft_puthexa(va_arg(ap, void *));
	else if (format == 'd')
		ft_putfloat(va_arg(ap ));
	else if (format == 'i')
		ft_putnbr(va_arg(ap, int));
	else if (format == 'u')
		ft_putufloat(va_arg(ap, unsigned float));
	else if (format == 'x')
		ft_
	else if (format == 'X')
		/* code */
	else if (format == '%')
		ft_putcharcount('%');
	return (print_lenght)
}

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

int ft_printf(const char *format, ...)
{
	int			*print_lenght;
	long int	i;
	va_list		ap;

	va_start(ap, format);
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
			print_lenght = ft_print(ap, format[i], print_lenght);
		}
		i++;
	}
	va_end(ap);
	return (print_lenght);
}
