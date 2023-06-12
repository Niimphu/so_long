# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 15:44:30 by yiwong            #+#    #+#              #
#    Updated: 2023/06/12 19:40:56 by yiwong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -O3

CFLAGS = -Wall -Wextra -Werror -g -Ofast -Isources -fsanitize=address

LDFLAGS = -fsanitize=address

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

MLX_DIR = dep/lib/mlx_linux

LIB_OS = -Ldep/lib/mlx_linux -lmlx

OS_FLAGS = -Imlx

API = -framework OpenGL -framework AppKit

LIBS = -Ldep/lib/libft -lft -Ldep/lib/ft_printf -lftprintf \
	-Ldep/lib/lib_me42 -lme42 $(LIB_OS)

CFLAGS += -Ilib/dep/mlx_linux -I/usr/X11/include

LDFLAGS += -Ldep/lib/mlx_linux -L/usr/X11/lib

LIBS += -lX11 -lXext -lft -lmlx

NAME = so_long

SHELL = bash

BLUE=\033[0;34m
GREEN = \033[0;92m
PURPLE = \033[0;35m
END = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@make -sC $(MLX_DIR)
	@echo -ne "$(PURPLE)Making $(END)"
	@echo -ne "$(PURPLE)███$(END)"
	@echo -ne "$(PURPLE)███$(END)"
	@make -sC dep/lib/libft
	@echo -ne "$(PURPLE)████$(END)"
	@make -sC dep/lib/ft_printf
	@echo -ne "$(PURPLE)████$(END)"
	@make -sC dep/lib/lib_me42
	@echo -e "$(PURPLE)███$(END)"
	@$(CC) $(LDFLAGS) $(OBJ) -o $(NAME) $(LIBS)
	@echo -e "$(GREEN)Make done!$(END)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

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
