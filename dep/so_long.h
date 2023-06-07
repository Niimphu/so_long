/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:54:16 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/07 20:21:00 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/libft/libft.h"
# include "lib/ft_printf/ft_printf.h"
# include "lib/lib_me42/lib_me42.h"
# include "lib/mlx_opengl/mlx.h"
# include "lib/get_next_line/get_next_line.h"

# include <fcntl.h>

# define RED "\033[1;31m"
# define RESET "\033[1;0m"
# define TRUE 1
# define FALSE 0


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

enum e_X11Events {
	KeyPress = 2,
	KeyRelease = 3,
	WindowClosed = 17
};

enum e_keycodes {
	ESC = 53,
	W = 13,
	A = 0,
	S = 1,
	D = 2
};

enum e_errorcodes {
	OK = 0,
	FAIL = -1,
	ARGN = 11,
	MAP_NAME = 12,
	NOT_RECTANGLE = 13,
	BAD_MAP = 14
};

#define red 0x00FF0000
#define green 0x0000FF00
#define blue 0x000000FF

int	arg_check(int argc, char **argv);

void error(int error_code);
char	**read_map(int fd);

void 	quit(t_vars *vars);
int		window_closed(t_vars *vars);


#endif