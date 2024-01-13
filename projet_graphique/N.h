/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   N.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:27:31 by ecunha            #+#    #+#             */
/*   Updated: 2024/01/13 19:20:11 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef N_H
# define N_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>

# define HEIGHT 1080
# define WIDTH 1920
# define STEP 20

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
	int		pos_x;
	int		pos_y;
	int		count;
	int		map_rows;
	int		map_columns
	void	*textures[5];
	int		textures_size[10];
	t_vars	ptr;
}				t_data;

#endif
