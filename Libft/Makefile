# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 08:52:38 by mfinette          #+#    #+#              #
#    Updated: 2022/11/18 03:31:49 by ecunha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = @rm -f
HEADER = libft.h
FILES = ft_memset \
		ft_bzero \
		ft_memcpy \
		ft_memmove \
		ft_memchr \
		ft_memcmp \
		ft_strlen \
		ft_strlcpy \
		ft_strlcat \
		ft_strchr \
		ft_strrchr \
		ft_strnstr \
		ft_strncmp \
		ft_strtrim \
		ft_split \
		ft_atoi \
		ft_itoa \
		ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_toupper \
		ft_tolower \
		ft_calloc \
		ft_strdup \
		ft_substr \
		ft_strmapi \
		ft_striteri \
		ft_strjoin \
		ft_putchar_fd \
		ft_putnbr_fd \
		ft_putstr_fd \
		ft_putendl_fd \


SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_BONUS = $(addprefix $(SRCS_DIR), $(addsuffix _bonus.c, $(FILES_BONUS)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_BONUS = $(addprefix $(OBJS_DIR), $(addsuffix _bonus.o, $(FILES_BONUS)))

%.o:%.c $(HEADER) Makefile
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c -o $@ $<
$(NAME): $(OBJS)
	@$(AR) $@ $^
	@echo "$(GREEN)					😳😎libft compiled perfectly!😎😳$(DEF_COLOR)"
	@echo "$(BLUE) MAKE COMMANDS LIST :$(DEF_COLOR)"
	@echo "$(CYAN) 		make clean (remove objects)$(DEF_COLOR)"
	@echo "$(CYAN) 		make fclean (remove objects and executables)$(DEF_COLOR)"
	@echo "$(CYAN) 		make re (cleans everything and recompiles)$(DEF_COLOR)"
	@echo "$(CYAN) 		make bonus (compiles the bonus exercices)$(DEF_COLOR)"
	@echo "$(GREEN)		make speed (does an AWESOME libft compilation ¡¡¡¡MUST TRY!!!!)$(DEF_COLOR)"
	
	
speed: 
	@open https://www.youtube.com/watch?v=dQw4w9WgXcQ

bonus: $(OBJS) $(OBJS_BONUS)
	@$(AR) $(NAME) $^
	@echo "$(GREEN)😳😎bonus compiled!😎😳$(DEF_COLOR)"

all: $(NAME)

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@echo "$(CYAN)libft object files cleaned!$(DEF_COLOR)"
	
fclean: clean
	@$(RM) $(NAME)
	@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re: clean all

.PHONY: bonus all clean fclean re speed