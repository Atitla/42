/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:17:09 by tgellon           #+#    #+#             */
/*   Updated: 2022/09/11 21:40:16 by dbaule           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_H
#define A_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	first_empty_case(char **tab, int *x, int *y);
int	ft_solve (char **tab);
int	game_over(char **tab);
void	input_number(char **tab, int x, int y, int i);
void	ft_pov_init(char **tab, char *str);
void	void_case(char **tab, int x, int y);
int	ft_check_argc(int argc);
int	ft_check_lines(char **tab, int x, int y);
int	ft_check_argv(char **argv);
int	ft_row_column(char **tab, int x, int y);
void	pt_putchar(char c);
void	ft_print_tab(char **tab);
#endif
