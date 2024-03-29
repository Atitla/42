/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:54:08 by ecunha            #+#    #+#             */
/*   Updated: 2023/12/05 14:34:18 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_print(va_list ap, char format)
{
	int	print_lenght;

	print_lenght = 0;
	if (format == 'c')
		print_lenght += ft_putcharcount(va_arg(ap, int), 1);
	else if (format == 's')
		print_lenght += ft_putstr(va_arg(ap, char *));
	else if (format == 'p')
		print_lenght += ft_putptr(va_arg(ap, void *));
	else if (format == 'd')
		print_lenght += ft_putnbr(va_arg(ap, int));
	else if (format == 'i')
		print_lenght += ft_putnbr(va_arg(ap, int));
	else if (format == 'u')
		print_lenght += ft_putunbr(va_arg(ap, unsigned int));
	else if (format == 'x')
		print_lenght += ft_puthexa(va_arg(ap, unsigned int), 0);
	else if (format == 'X')
		print_lenght += ft_puthexa(va_arg(ap, unsigned int), 1);
	else if (format == '%')
		print_lenght += ft_putcharcount('%', 1);
	return (print_lenght);
}

int	ft_printf(const char *format, ...)
{
	int			print_lenght;
	int			i;
	va_list		ap;

	va_start(ap, format);
	i = 0;
	print_lenght = 0;
	if (write(1, 0, 0) == -1)
		return (-1);
	while (format[i])
	{
		if ((char)format[i] != '%')
			print_lenght += ft_putcharcount(format[i], 1);
		else
		{
			if (format[i] == '%' && format[i + 1] == '\0')
			{
				return (print_lenght);
			}
			print_lenght += ft_print(ap, format[++i]);
		}
		i++;
	}
	va_end(ap);
	return (print_lenght);
}
