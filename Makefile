# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 15:44:30 by yiwong            #+#    #+#              #
#    Updated: 2023/06/11 16:19:01 by yiwong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -O3

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRC = src/main.c \
		src/ready_check.c \
		src/read_map.c \
		src/map_checkers.c \
		src/so_long.c \
		src/input_handler.c \
		src/error.c \
		src/quit.c \
		src/map_utils.c \
		$(GNL)

GNL = dep/lib/get_next_line/get_next_line.c \
		dep/lib/get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

MLX_DIR = dep/lib/mlx_opengl

LIB_OS = -Ldep/lib/mlx_opengl -lmlx

OS_FLAGS = -Imlx

API = -framework OpenGL -framework AppKit

LIBS = -Ldep/lib/libft -lft -Ldep/lib/ft_printf -lftprintf \
	-Ldep/lib/lib_me42 -lme42 $(LIB_OS)

NAME = so_long

SHELL = bash

BLUE=\033[0;34m
GREEN = \033[0;92m
PURPLE = \033[0;35m
END = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo -ne "$(PURPLE)Making $(END)"
	@echo -ne "$(PURPLE)███$(END)"
	@make -sC $(MLX_DIR)
	@echo -ne "$(PURPLE)███$(END)"
	@make -sC dep/lib/libft
	@echo -ne "$(PURPLE)████$(END)"
	@make -sC dep/lib/ft_printf
	@echo -ne "$(PURPLE)████$(END)"
	@make -sC dep/lib/lib_me42
	@echo -e "$(PURPLE)███$(END)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(API) -o $(NAME)
	@echo -e "$(GREEN)Make done!$(END)"

%.o: %.c
	@$(CC) $(CFLAGS) $(OS_FLAGS) -c $< -o $@

clean:
	@echo -ne "$(BLUE)Cleaning $(END)"
	@echo -ne "$(BLUE)███$(END)"
	@make clean -sC $(MLX_DIR)
	@echo -ne "$(BLUE)███$(END)"
	@make fclean -sC dep/lib/libft
	@echo -ne "$(BLUE)███$(END)"
	@make fclean -sC dep/lib/ft_printf
	@echo -ne "$(BLUE)███$(END)"
	@make fclean -sC dep/lib/lib_me42
	@echo -e "$(BLUE)███$(END)"
	@rm -f $(OBJ)
	@echo -e "$(GREEN)Cleaning done!$(END)"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
