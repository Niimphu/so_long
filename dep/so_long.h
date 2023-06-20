/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:54:16 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/17 03:50:31 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/libft/libft.h"
# include "lib/ft_printf/ft_printf.h"
# include "lib/lib_me42/lib_me42.h"
# include "lib/mlx_linux/mlx.h"
# include "lib/get_next_line/get_next_line.h"

# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>

# define RED "\033[1;31m"
# define RESET "\033[1;0m"

# define TRUE 1
# define FALSE 0

# define OK 0
# define FAIL (-1)
# define ARGN 11
# define MAP_NAME 12
# define BAD_MAP 13

# define X 1
# define Y 0

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
	void	*player_image;
	char	**map;
	int 	collectible_count;
	int		map_size[2];
	int 	exit_coords[2];
	int 	move_count;
}				t_vars;

int		arg_check(int argc, char **argv);

int		open_map_file(char *name);
char	**read_map(int fd, char *name);
int		map_check(char *name);
int		is_map_valid(char **map);

int		init(char *name, t_vars *vars);

int		key_pressed(int keycode, t_vars *vars);
int 	move_input(t_vars *vars, int keycode);

int 	count_collectibles(t_vars *vars);

int		so_long(t_vars *vars);

int 	draw_entities(t_vars *vars);
int		draw_player(t_vars *vars);
int		draw_background(t_vars *vars);

int		window_closed(t_vars *vars);
void	error(int error_code);
void 	quit(t_vars *vars);

void	print_map(char **map);
int		*locate_first(char **map, char c, int coords[2]);
char	**propagate_path(char **map);
int		*get_map_size(char **map, int size[2]);

#endif