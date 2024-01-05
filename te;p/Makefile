# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 03:21:58 by ecunha            #+#    #+#              #
#    Updated: 2024/01/05 17:24:45 by ecunha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = proj
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DFLAGS = -ggdb3
RM = rm -f
HEADER = N.h
FILES = main

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

ifeq ($(DEBUG),yes)
CFLAGS += $(DFLAGS)
endif

%.o:%.c $(HEADER)
	${CC} ${CFLAGS} -I/usr/local/include -c $< -o ${<:.c=.o}
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I/usr/local/include -lmlx -lXext -lX11 -o $@ $^
all: $(NAME)

debug:
	make DEBUG=yes
clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
