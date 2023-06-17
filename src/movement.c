/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:33:20 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/17 16:09:29 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 4

int check_valid_move(t_vars *vars, int direction, int coords[2]);

int move_input(t_vars *vars, int keycode)
{
	int direction;
	int is_move_possible;
	int coords[2];

	if (keycode == XK_w)
		direction = UP;
	else if (keycode == XK_a)
		direction = LEFT;
	else if (keycode == XK_s)
		direction = RIGHT;
	else if (keycode == XK_d)
		direction = DOWN;
	else
		direction = -1;
	if (!direction)
		return (1);
	locate_first(vars->map, 'P', coords);
	is_move_possible = check_valid_move(vars, direction, coords);
	if (is_move_possible)
		ft_printf("Good move\n");
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
	if (vars->map[coords[X]][coords[Y]] != '1')
		return (TRUE);
	return (FALSE);
}