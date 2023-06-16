NAME = mlx_test
CC = gcc
CFLAGS = -Wall -Wextra
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
