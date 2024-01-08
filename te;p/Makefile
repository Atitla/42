# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 03:21:58 by ecunha            #+#    #+#              #
#    Updated: 2024/01/08 15:40:08 by ecunha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = proj
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DFLAGS = -ggdb3
LIB = mlx/libmlx.a mlx/libmlx_Linux.a
LDFLAGS = -Lminilibx/mlx_Linux -Lminilibx/mlx -Lminilibx/mlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
RM = rm -f
HEADER = N.h
FILES = main

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

ifeq ($(DEBUG),yes)
CFLAGS += $(DFLAGS)
endif

%.o:%.c $(HEADER)
	${CC} ${CFLAGS} $^ $(LIB) $(LDFLAGS) -o $@ $<
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIB) -o $@ $^
all: $(NAME)

debug:
	make DEBUG=yes
clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
