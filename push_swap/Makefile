# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 03:21:58 by ecunha            #+#    #+#              #
#    Updated: 2023/11/29 14:59:44 by ecunha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -ggdb3 -DDEBUG
RM = rm -f
HEADER = push_swap.h
FILES = push_swap \
		push_swap_utils \
		rules

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

LIB_DIR := libftmax/
LIB := $(LIB_DIR)libftmax.a

%.o:%.c $(HEADER)
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
$(LIB):
	$(MAKE) -C $(LIB_DIR)
$(NAME): $(OBJS) $(LIB)
	$(CC) -o $@ $^
all: $(NAME)

debug: CFLAGS += $(DEBUG_FLAGS)
debug: all

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(MAKE) -C $(LIB_DIR) clean
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean
re: fclean all
debug:
.PHONY: all clean fclean re
