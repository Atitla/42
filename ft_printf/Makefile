# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 03:21:58 by ecunha            #+#    #+#              #
#    Updated: 2023/05/16 13:12:58 by ecunha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
HEADER = printf.h
FILES = ft_printf \
		ft_putcharcount \
		ft_putstr \
		ft_putnbr \
		ft_puthexa \
		ft_putptr \
		ft_putunbr \

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER) -c -o $@ $<
$(NAME): $(OBJS)
	$(AR) $@ $^
all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
