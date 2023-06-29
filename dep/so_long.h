/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:54:16 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/28 23:58:07 by yiwong           ###   ########.fr       */
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
# define NOT_ENOUGH_ENTITIES 16
# define BAD_BORDER 17
# define NO_PATH 18
# define INVALID_CHAR 19

# define X 1
# define Y 0

# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 4

typedef struct s_ent {
	char			id;
	int				coords[2];
	struct s_ent	*next;
}					t_ent;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*player_images[9];
	void	*enemy_images[9];
	void	*explosion_images[9];
	void	*collectible_images[5];
	void	*exit_images[3];
	void	*wall;
	void	*background;
	t_ent	*enemies;
	int		frame;
	char	**map;
	char	*name;
	int		collectible_count;
	int		map_size[2];
	int		exit_coords[2];
	int		move_count;
}				t_vars;

int		arg_check(int argc, char **argv);

int		open_map_file(char *name);
char	**read_map(int fd, char *name);
int		new_map(t_vars *vars);
int		map_check(char *name);
t_ent	*create_enemy_list(t_vars *vars);

int		validate_map(char **map);
int		check_map_rectangular(char **map);
int		check_entity_count(char **map);
int		check_map_border(char **map);
int		check_map_pathing(char **map);
int		check_invalid_characters(char **map);

int		get_images_from_textures(t_vars *vars);
int		draw(t_vars *vars);
int		draw_player(t_vars *vars);
int		draw_entities(t_vars *vars);
int		draw_background(t_vars *vars);
int		draw_enemy(t_vars *vars, int x, int y);
int		update_move_counter(t_vars *vars);

int		initialise(char *name, t_vars *vars);
int		so_long(t_vars *vars);
int		restart_level(t_vars *vars);
int		loop(t_vars *vars);

int		is_player_move_valid(t_vars *vars, int direction, int coords[2]);
int		is_enemy_in_target(t_vars *vars, int target[2]);
int		is_enemy_move_valid(t_vars *vars, int i, int j);
int		move_enemies(t_vars *vars);
void	boom(t_vars *vars);


int		*locate_first(char **map, char c, int coords[2]);
int		*get_map_size(char **map, int size[2]);
int		move_input(t_vars *vars, int keycode);
int		count_collectibles(t_vars *vars);

void	free_list(t_ent *list);
int		key_pressed(int keycode, t_vars *vars);
int		window_closed(t_vars *vars);
void	error_exit(int error_code);
void	quit(t_vars *vars);

void	print_map(char **map);
void	print_list(t_ent *list);

#endif