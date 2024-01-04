# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 03:21:58 by ecunha            #+#    #+#              #
#    Updated: 2024/01/04 15:14:04 by ecunha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
DFLAGS = -ggdb3
RM = rm -f
HEADER = pipex.h
FILES = main \
		strfunc \
		pipex_utils \
		pipex \
		ft_split

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

ifeq ($(DEBUG),yes)
CFLAGS += $(DFLAGS)
endif

%.o:%.c $(HEADER)
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
all: $(NAME)

debug:
	make DEBUG=yes
clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
