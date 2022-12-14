/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:54:08 by ecunha            #+#    #+#             */
/*   Updated: 2022/12/14 22:06:44 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print(va_list ap, char format)
{
	int	print_lenght;

	print_lenght = 0;
	if (format == 'c')
		print_lenght += ft_putcharcount(va_arg(ap, int));
	else if (format == 's')
		print_lenght += ft_putstr(va_arg(ap, char *));
	//else if (format == 'p')
	//	print_lenght += ft_puthexa(va_arg(ap, void *));
	//else if (format == 'd')
	//	print_lenght += ft_putnbr(va_arg(ap, int));
	else if (format == 'i')
		print_lenght += ft_putnbr(va_arg(ap, int));
	else if (format == 'u')
		print_lenght += ft_putunbr(va_arg(ap, unsigned int));
	//else if (format == 'x')
	//	print_lenght += ft_
	//else if (format == 'X')
	//	print_lenght += /* code */
	else if (format == '%')
		print_lenght += ft_putcharcount('%');
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
	while (format[i])
	{
		if ((char)format[i] != '%')
			print_lenght += ft_putcharcount(format[i]);
		else
			print_lenght += ft_print(ap, format[++i]);
		i++;
	}
	va_end(ap);
	return (print_lenght);
}

int	main(int argc, char const *argv[])
{
	(void)argc;
	ft_printf("\n%i",ft_printf(argv[1], atoi(argv[2])));
	printf("\n");
	printf("\n%i",printf(argv[1], atoi(argv[2])));
	printf("\n");
	return 0;
}
