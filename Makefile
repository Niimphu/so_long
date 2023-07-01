# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 15:44:30 by yiwong            #+#    #+#              #
#    Updated: 2023/06/16 18:45:03 by yiwong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -Isources

LDFLAGS =

SRC = src/main.c \
		src/initialise.c \
		src/ready_check.c \
		src/map_functions/open_map.c \
		src/map_functions/read_map.c \
		src/map_functions/map_utils.c \
		src/map_checkers/validate_map.c \
		src/map_checkers/check_map_border.c \
		src/map_checkers/check_map_duplicate.c \
		src/map_checkers/check_map_pathing.c \
		src/map_checkers/check_map_rectangular.c \
		src/map_checkers/check_invalid_characters.c \
		src/so_long.c \
		src/bonus/enemy_list.c \
		src/bonus/enemy_movement.c \
		src/bonus/enemy_logic.c \
		src/bonus/time_loop.c \
		src/draw/draw.c \
		src/draw/get_images.c \
		src/draw/draw_characters.c \
		src/draw/draw_map.c \
		src/input_handler.c \
		src/player_movement.c \
		src/move_checks.c \
		src/error.c \
		src/quit.c \
		$(GNL)

BONUS_SRC = src/main.c \
		src/initialise.c \
		src/ready_check.c \
		src/map_functions/open_map.c \
		src/map_functions/read_map.c \
		src/map_functions/map_utils.c \
		src/map_checkers/validate_map.c \
		src/map_checkers/check_map_border.c \
		src/map_checkers/check_map_duplicate.c \
		src/map_checkers/check_map_pathing.c \
		src/map_checkers/check_map_rectangular.c \
		src/bonus/so_long_bonus.c \
		src/bonus/time_loop.c \
		src/bonus/check_invalid_character_bonus.c \
		src/bonus/enemy_movement.c \
		src/bonus/enemy_list.c \
		src/bonus/enemy_logic.c \
		src/draw/draw.c \
		src/draw/get_images.c \
		src/draw/draw_characters.c \
		src/draw/draw_map.c \
		src/input_handler.c \
		src/player_movement.c \
		src/move_checks.c \
		src/error.c \
		src/quit.c \
		$(GNL)

GNL = dep/lib/get_next_line/get_next_line.c \
		dep/lib/get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

MLX_DIR = dep/lib/mlx_linux

LIB_OS = -Ldep/lib/mlx_linux -lmlx

LIBS = -Ldep/lib/libft -lft -Ldep/lib/ft_printf -lftprintf \
	-Ldep/lib/lib_me42 -lme42 $(LIB_OS)

CFLAGS += -Ilib/dep/mlx_linux -I/usr/X11/include

LDFLAGS += -Ldep/lib/mlx_linux -L/usr/X11/lib

LIBS += -lX11 -lXext -lft -lmlx

NAME = so_long

BONUS = so_long_bonus

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
	@$(CC) $(LDFLAGS) $(OBJ) -o $(NAME) $(LIBS)
	@echo -e "$(GREEN)Make done!$(END)"

$(BONUS): $(BONUS_OBJ)
	@echo -ne "$(PURPLE)Making bonus $(END)"
	@echo -ne "$(PURPLE)███$(END)"
	@make -sC $(MLX_DIR)
	@echo -ne "$(PURPLE)███$(END)"
	@make -sC dep/lib/libft
	@echo -ne "$(PURPLE)████$(END)"
	@make -sC dep/lib/ft_printf
	@echo -ne "$(PURPLE)████$(END)"
	@make -sC dep/lib/lib_me42
	@echo -e "$(PURPLE)███$(END)"
	@$(CC) $(LDFLAGS) $(BONUS_OBJ) -o $(BONUS) $(LIBS)
	@echo -e "$(GREEN)Make bonus done!$(END)"

bonus: $(BONUS)

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
	@rm -f $(OBJ) $(BONUS_OBJ)
	@echo -e "$(GREEN)Cleaning done!$(END)"

fclean: clean
	@rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
