/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:02:34 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/28 23:51:27 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

int	is_player_move_valid(t_vars *vars, int direction, int coords[2])
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

int	is_enemy_move_valid(t_vars *vars, int i, int j)
{
	if (ft_strchr("1ECHhVv", vars->map[i][j]))
		return (FALSE);
	return (TRUE);
}

int	is_enemy_in_target(t_vars *vars, int target[2])
{
	if (ft_strchr("HhVv", vars->map[target[Y]][target[X]]))
		return (TRUE);
	else
		return (FALSE);
}
