/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:54:16 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/25 14:05:23 by yiwong           ###   ########.fr       */
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

# define TRUE 1
# define FALSE 0

# define OK 0
# define FAIL (-1)
# define ARGN 11
# define MAP_NAME 12
# define BAD_MAP 13
# define NON_RECT 14
# define DUP_ENTITIES 15
# define BAD_BORDER 16
# define NO_PATH 17
# define INVALID_CHAR 18

# define X 1
# define Y 0

# define P 0
# define E 0
# define C 1
# define W 2
# define BG 3

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*images[5];
	void	*player_images[9];
	int		frame;
	char	**map;
	int		collectible_count;
	int		map_size[2];
	int		exit_coords[2];
	int		move_count;
}				t_vars;

int		arg_check(int argc, char **argv);

int		open_map_file(char *name);
char	**read_map(int fd, char *name);
int		map_check(char *name);

int		validate_map(char **map);
int		check_map_rectangular(char **map);
int		check_map_duplicate_entities(char **map);
int		check_map_border(char **map);
int		check_map_pathing(char **map);
int		check_invalid_characters(char **map);

int		get_images_from_textures(t_vars *vars);
int		draw(t_vars *vars);
int		draw_player(t_vars *vars);
int		draw_entities(t_vars *vars);
int		draw_background(t_vars *vars);
int		update_move_counter(t_vars *vars);

int		initialise(char *name, t_vars *vars);
int		so_long(t_vars *vars);

int		*locate_first(char **map, char c, int coords[2]);
int		*get_map_size(char **map, int size[2]);
int		move_input(t_vars *vars, int keycode);
int		count_collectibles(t_vars *vars);

int		key_pressed(int keycode, t_vars *vars);
int		window_closed(t_vars *vars);
void	error_exit(int error_code);
void	quit(t_vars *vars);

void	print_map(char **map);

#endif