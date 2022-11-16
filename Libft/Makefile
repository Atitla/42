# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 08:52:38 by mfinette          #+#    #+#              #
#    Updated: 2022/11/16 02:19:43 by ecunha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = @rm -f
HEADER = libft.h
DEF_COLOR = \033[0;39m
YELLOW = \033[0;93m
GREEN = \033[0;92m
BLUE = \033[0;94m
CYAN = \033[0;96m
RED = \033[0;31m

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
		ft_atoi \
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











FILES_BONUS = 	ft_lstnew \
	  		ft_lstadd_front \
	  		ft_lstsize \
	  		ft_lstlast \
	  		ft_lstadd_back \
	  		ft_lstdelone \
	  		ft_lstclear \
	  		ft_lstiter \
	  		ft_lstmap

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