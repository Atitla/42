/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:27:31 by ecunha            #+#    #+#             */
/*   Updated: 2024/01/22 16:30:57 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"

# define STEP 64
# define PLAYER "textures/player_64x64.xpm"
# define FLOOR "textures/floor_64x64.xpm"
# define WALL "textures/wall_64x64.xpm"
# define COIN "textures/coin_64x64.xpm"
# define EXITS "textures/exit_64x64.xpm"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_data
{
	int		pos_x;
	int		pos_y;
	int		count;
	int		coins_earn;
	int		map_rows;
	int		map_columns;
	char	**map;
	void	*textures[5];
	int		text_size[10];
	t_vars	ptr;
}				t_data;

char	**ft_free(char **array);
char	**ft_split(const char *str, char c);
int		render_next_frame(t_data *img);
void	render_with_map(t_data *img, int i, int j);
void	print_texture(t_data *img, int i, int j, int text_index);
void	import_textures(t_data *data);
int		close_mlx(t_data *vars);
void	is_map_dot_ber(char *str, t_data *data);
int		map_parser(char *str, t_data *data);
char	*get_first_row(char *str, int *fd, t_data *data);
int		map_border_valid(char *str, t_data *data);
int		check_first_line(char *str, t_data *data);
int		pathfinding(t_data *data);
void	place_player(t_data *data);
int		check_required(int exit_count, int player, \
		int collectibles, t_data *data);
int		map_inside_valid(t_data *data);
int		coin_left(t_data *data);
int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char	**matrix_cpy_alloc(t_data *data);
int		ft_putnbr(int nb);
void	fill_map(char **temp_matrix, int x, int y);
int		ft_putcharcount(int nbr, int lgt);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *string, int searchedChar );
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t elementCount, size_t elementSize);
size_t	ft_strlen_st(const char *theString);

#endif
