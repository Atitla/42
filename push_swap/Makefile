# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 03:21:58 by ecunha            #+#    #+#              #
#    Updated: 2023/12/05 14:40:18 by ecunha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
HEADER = push_swap.h
FILES = push_swap \
		push_swap_utils \
		push_swap_utils_2 \
		rules \
		ft_error \
		sort_little_tab \
		ft_strcmp \
		ft_split \
		ft_atoi \
		ft_strcmp \
		ft_isdigit \
		ft_printf \
		ft_putcharcount \
		ft_putstr \
		ft_putnbr \
		ft_puthexa \
		ft_putptr \
		ft_putunbr \

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

%.o:%.c $(HEADER)
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
