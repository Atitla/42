CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Lminilibx/mlx_Linux -Lminilibx/mlx -Lminilibx/mlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
LIB = minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a
OBJ_DIR = obj
SRC = main.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
EXEC = so_long

RM = rm -f

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $^ $(LIB) $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC_DIR) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(EXEC)

re: fclean all

.PHONY: all clean fclean re
