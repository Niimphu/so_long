# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 15:44:30 by yiwong            #+#    #+#              #
#    Updated: 2023/05/29 18:18:43 by yiwong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC = src/main.c \
		src/so_long.c

OBJ = $(SRC:.c=.o)

LIBS = -Ldep/lib/libft -lft -Ldep/lib/ft_printf -lftprintf \
	-Ldep/lib/lib_me42 -lme42 -Ldep/mlx -lmlx

NAME = so_long

all: $(NAME)

$(NAME): $(OBJ)
	@make -sC dep/lib/libft
	@make -sC dep/lib/ft_printf
	@make -sC dep/lib/lib_me42
	@make -sC dep/mlx
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make fclean -sC dep/lib/libft
	@make fclean -sC dep/lib/ft_printf
	@make fclean -sC dep/lib/lib_me42
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
