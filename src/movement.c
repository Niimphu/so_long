/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:33:20 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/17 17:06:57 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 4

int check_valid_move(t_vars *vars, int direction, int coords[2]);
int move_player(t_vars *vars, int coords[2], int target[2]);

int move_input(t_vars *vars, int keycode)
{
	int direction;
	int is_move_possible;
	int coords[2];
	int target[2];

	direction = -1;
	if (keycode == XK_w)
		direction = UP;
	else if (keycode == XK_a)
		direction = LEFT;
	else if (keycode == XK_s)
		direction = RIGHT;
	else if (keycode == XK_d)
		direction = DOWN;
	locate_first(vars->map, 'P', coords);
	target[X] = coords[X];
	target[Y] = coords[Y];
	is_move_possible = check_valid_move(vars, direction, target);
	if (is_move_possible)
		move_player(vars, coords, target);
	else
		ft_printf("Bad move\n");
	return (0);
}

int check_valid_move(t_vars *vars, int direction, int coords[2])
{
	if (direction == UP)
		coords[X] -= 1;
	else if (direction == DOWN)
		coords[X] += 1;
	else if (direction == LEFT)
		coords[Y] -= 1;
	else if (direction == RIGHT)
		coords[Y] += 1;
	if (vars->map[coords[Y]][coords[X]] != '1')
		return (TRUE);
	return (FALSE);
}

int move_player(t_vars *vars, int coords[2], int target[2])
{
	vars->map[coords[Y]][coords[X]] = '0';
	vars->map[target[Y]][target[X]] = 'P';
	return (0);
}
