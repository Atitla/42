# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 03:21:58 by ecunha            #+#    #+#              #
#    Updated: 2023/05/19 15:52:59 by ecunha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mlx
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
HEADER = ft_printf.h
FILES = main

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@
$(NAME): $(OBJ)
	$(CC) $(OBJ) -L/nfs/homes/ecunha/mlx/libmlx_Linux -l/nfs/homes/ecunha/mlx/libmlx_Linux -L/nfs/homes/ecunha/mlx/libmlx -lm -lz -o $(NAME)
all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
