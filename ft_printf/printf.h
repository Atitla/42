/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 04:57:57 by ecunha            #+#    #+#             */
/*   Updated: 2022/12/13 05:18:08 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putcharcount(int nbr);
int	ft_putnbr(int nb);

#endif