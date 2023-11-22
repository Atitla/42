# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 03:21:58 by ecunha            #+#    #+#              #
#    Updated: 2023/11/22 14:03:44 by ecunha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
HEADER = push_swap.h
FILES = push_swap

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

# Path to the library and its Makefile
LIB_DIR := libftmax/
LIB_MAKEFILE := libftmax/Makefile

# Include the library's Makefile
include $(LIB_MAKEFILE)

%.o:%.c $(HEADER) libftmax.a
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -L$(LIB_DIR) -llibftmax
$(NAME): $(OBJS)
	$(CC) $@ $^
all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
