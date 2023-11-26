# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 03:21:58 by ecunha            #+#    #+#              #
#    Updated: 2023/11/25 14:56:27 by ecunha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile principal

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
HEADER = push_swap.h
FILES = push_swap

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

# Path to the library
LIB_DIR := libftmax/
LIB := $(LIB_DIR)libftmax.a

%.o:%.c $(HEADER)
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
$(LIB):
	$(MAKE) -C $(LIB_DIR)
$(NAME): $(OBJS) $(LIB)
	$(CC) -o $@ $^
all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(MAKE) -C $(LIB_DIR) clean
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean
re: fclean all

.PHONY: all clean fclean re
