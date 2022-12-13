/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:04:29 by ecunha            #+#    #+#             */
/*   Updated: 2022/09/21 16:07:40 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	n;

	(void) argc;
	i = 0;
	n = 0;
	while (argv[0][i])
		i++;
	write(1, ".", 1);
	while (n++ < (i - 1) )
		write(1, &argv[0][n], 1);
	write(1, "\n", 1);
}
