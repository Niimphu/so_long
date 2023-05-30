# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 15:44:30 by yiwong            #+#    #+#              #
#    Updated: 2023/05/30 16:56:36 by yiwong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC = src/main.c \
		src/so_long.c

OBJ = $(SRC:.c=.o)

LIBS = -Ldep/lib/libft -lft -Ldep/lib/ft_printf -lftprintf \
	-Ldep/lib/lib_me42 -lme42 -Ldep/mlx -lmlx

MAC = -framework OpenGL -framework AppKit

NAME = so_long

all: $(NAME)

$(NAME): $(OBJ)
	@make -sC dep/lib/libft
	@make -sC dep/lib/ft_printf
	@make -sC dep/lib/lib_me42
	@make -C dep/mlx
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(MAC) -o $(NAME)


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make fclean -sC dep/lib/libft
	@make fclean -sC dep/lib/ft_printf
	@make fclean -sC dep/lib/lib_me42
	@make clean -sC dep/mlx
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
