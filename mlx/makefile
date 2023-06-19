NAME = mlx_test
CC = gcc
CFLAGS = -Wall -Wextra
RM = rm -f
AR = ar rcs
HEADER = printf.h
FILES = main

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
