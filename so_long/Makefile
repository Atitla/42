# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 03:21:58 by ecunha            #+#    #+#              #
#    Updated: 2024/01/22 15:13:10 by ecunha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DFLAGS = -ggdb3
LIB = mlx/libmlx_Linux.a
LDFLAGS = -Lmlx/mlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11
RM = rm -f
HEADER = so_long.h
FILES = so_long \
		render_map \
		map \
		map_2 \
		string_func \
		ft_split \
		ft_putnbr \
		ft_putcharcount \
		get_next_line \
		get_next_line_utils

OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

ifeq ($(DEBUG),yes)
CFLAGS += $(DFLAGS)
endif

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -L$(LIB) -c -o $@ $<
$(NAME): $(OBJS)
	${CC} $^ $(LIB) $(LDFLAGS) -o $@
all: $(NAME)

debug:
	make DEBUG=yes
clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
