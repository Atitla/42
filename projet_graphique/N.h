/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   N.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:27:31 by ecunha            #+#    #+#             */
/*   Updated: 2024/01/18 21:45:33 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef N_H
# define N_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"

# define HEIGHT 1080
# define WIDTH 1920
# define STEP 16
# define PLAYER "textures/player_16x16.xpm"
# define FLOOR "textures/floor_16x16.xpm"
# define WALL "textures/wall_16x16.xpm"
# define COIN "textures/coin_16x16.xpm"
# define EXITS "textures/exit_16x16.xpm"

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_data {
	t_vars	ptr;
	int		pos_x;
	int		pos_y;
	int		count;
	int		coins_earn;
	int		map_rows;
	int		map_columns;
	char	**map;
	void	*textures[5];
	int		text_size[10];
}				t_data;

char	**ft_free(char **array);
char	**ft_split(const char *str, char c);

#endif
