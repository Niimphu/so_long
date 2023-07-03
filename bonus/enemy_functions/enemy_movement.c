/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:40:04 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/03 15:42:47 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../dep/so_long_bonus.h"

int	move_enemies(t_bvars *vars)
{
	t_ent	*enemies;

	enemies = vars->enemies;
	while (enemies)
	{
		if (check_and_move_enemy(vars, enemies))
			return (1);
		enemies = enemies->next;
	}
	return (0);
}

int	move_enemy(t_bvars *vars, t_ent *enemies, int target[2])
{
	vars->map[target[Y]][target[X]] = enemies->id;
	vars->map[enemies->coords[Y]][enemies->coords[X]] = '0';
	enemies->coords[X] = target[X];
	enemies->coords[Y] = target[Y];
	return (0);
}

int	flip_enemy(t_ent *enemies)
{
	if (enemies->id == 'H')
		enemies->id = 'h';
	else if (enemies->id == 'h')
		enemies->id = 'H';
	else if (enemies->id == 'V')
		enemies->id = 'v';
	else if (enemies->id == 'v')
		enemies->id = 'V';
	return (0);
}

int	enemy_walked_into_player(t_bvars *vars, t_ent *enemies, int target[2])
{
	vars->map[target[Y]][target[X]] = 'B';
	vars->map[enemies->coords[Y]][enemies->coords[X]] = '0';
	boom(vars);
	return (1);
}
