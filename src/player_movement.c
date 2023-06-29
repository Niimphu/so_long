/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:33:20 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/26 20:21:51 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

int	move_player(t_vars *vars, int coords[2], int target[2]);
int	exit_reached(t_vars *vars);
int	player_walked_into_enemy(t_vars *vars, int coords[2], int target[2]);

int	move_input(t_vars *vars, int keycode)
{
	int	direction;
	int	is_move_possible;
	int	coords[2];
	int	target[2];

	if (!locate_first(vars->map, 'P', coords))
		return (1);
	direction = -1;
	if (keycode == XK_w || keycode == XK_Up)
		direction = UP;
	else if (keycode == XK_a || keycode == XK_Left)
		direction = LEFT;
	else if (keycode == XK_s || keycode == XK_Down)
		direction = DOWN;
	else if (keycode == XK_d || keycode == XK_Right)
		direction = RIGHT;
	target[X] = coords[X];
	target[Y] = coords[Y];
	is_move_possible = is_player_move_valid(vars, direction, target);
	if (is_move_possible)
		move_player(vars, coords, target);
	else
		return (0);
	return (0);
}

int	move_player(t_vars *vars, int coords[2], int target[2])
{
	int	exit_coords[2];

	if (vars->map[target[Y]][target[X]] == 'C')
		vars->collectible_count -= 1;
	else if (is_enemy_in_target(vars, target))
		return (player_walked_into_enemy(vars, coords, target));
	if (coords[X] == vars->exit_coords[X] && coords[Y] == vars->exit_coords[Y])
		vars->map[coords[Y]][coords[X]] = 'E';
	else
		vars->map[coords[Y]][coords[X]] = '0';
	vars->map[target[Y]][target[X]] = 'P';
	vars->move_count += 1;
	move_enemies(vars);
	if (vars->collectible_count == 0
		&& !locate_first(vars->map, 'E', exit_coords))
		exit_reached(vars);
	return (0);
}

int	exit_reached(t_vars *vars)
{
	if (ft_strncmp(vars->name, "default", 7))
		quit(vars);
	else if (!ft_strncmp(vars->name, "default", 8))
		vars->name = "default2";
	else if (!ft_strncmp(vars->name, "default2", 8))
		vars->name = "default3";
	else if (!ft_strncmp(vars->name, "default3", 8))
		vars->name = "default4";
	else if (!ft_strncmp(vars->name, "default4", 8))
		vars->name = "default5";
	else if (!ft_strncmp(vars->name, "default5", 8))
		vars->name = "default6";
	else if (!ft_strncmp(vars->name, "default6", 8))
		vars->name = "default7";
	else
		quit(vars);
	new_map(vars);
	return (0);
}

int	player_walked_into_enemy(t_vars *vars, int coords[2], int target[2])
{
	vars->map[target[Y]][target[X]] = 'B';
	vars->map[coords[Y]][coords[X]] = '0';
	boom(vars);
	return (0);
}
