/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 04:57:57 by ecunha            #+#    #+#             */
/*   Updated: 2023/05/15 11:57:39 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>

int	ft_printf(const char *format, ...);
int	ft_putcharcount(int nbr, int lgt);
int	ft_putnbr(int nb);
int	ft_putunbr(unsigned int nb);
int	ft_putstr(char *str);
int	ft_putptr(void *ptr);
int	ft_puthexa(unsigned long nbr, int upper);
#endif
