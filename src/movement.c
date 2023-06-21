/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:33:20 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/21 18:09:04 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 4

int	check_valid_move(t_vars *vars, int direction, int coords[2]);
int	move_player(t_vars *vars, int coords[2], int target[2]);

int	move_input(t_vars *vars, int keycode)
{
	int	direction;
	int	is_move_possible;
	int	coords[2];
	int	target[2];

	direction = -1;
	if (keycode == XK_w)
		direction = UP;
	else if (keycode == XK_a)
		direction = LEFT;
	else if (keycode == XK_s)
		direction = DOWN;
	else if (keycode == XK_d)
		direction = RIGHT;
	locate_first(vars->map, 'P', coords);
	target[X] = coords[X];
	target[Y] = coords[Y];
	is_move_possible = check_valid_move(vars, direction, target);
	if (is_move_possible)
		move_player(vars, coords, target);
	else
		return (0);
	return (0);
}

int	check_valid_move(t_vars *vars, int direction, int coords[2])
{
	if (direction == UP)
		coords[Y] -= 1;
	else if (direction == DOWN)
		coords[Y] += 1;
	else if (direction == LEFT)
		coords[X] -= 1;
	else if (direction == RIGHT)
		coords[X] += 1;
	if (vars->map[coords[Y]][coords[X]] != '1')
		return (TRUE);
	return (FALSE);
}

int	move_player(t_vars *vars, int coords[2], int target[2])
{
	int	exit_coords[2];

	if (vars->map[target[Y]][target[X]] == 'C')
		vars->collectible_count -= 1;
	if (coords[X] == vars->exit_coords[X] && coords[Y] == vars->exit_coords[Y])
		vars->map[coords[Y]][coords[X]] = 'E';
	else
		vars->map[coords[Y]][coords[X]] = '0';
	vars->map[target[Y]][target[X]] = 'P';
	vars->move_count += 1;
	if (vars->collectible_count == 0
		&& !locate_first(vars->map, 'E', exit_coords))
		quit(vars);
	return (0);
}
