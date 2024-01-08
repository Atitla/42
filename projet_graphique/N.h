/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   N.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:27:31 by ecunha            #+#    #+#             */
/*   Updated: 2024/01/08 16:43:26 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef N_H
# define N_H

# include "mlx.h"
# include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

#endif
