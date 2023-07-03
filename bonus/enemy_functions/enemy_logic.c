/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_logic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:26:03 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/03 15:42:47 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../dep/so_long_bonus.h"

int	check_and_move_enemy(t_bvars *vars, t_ent *enemies)
{
	int	target[2];

	target[X] = 0;
	target[Y] = 0;
	get_enemy_target(enemies, target);
	if (!is_enemy_move_valid(vars, target[Y], target[X]))
	{
		flip_enemy(enemies);
		get_enemy_target(enemies, target);
	}
	if (vars->map[target[Y]][target[X]] == 'P')
		return (enemy_walked_into_player(vars, enemies, target));
	else
		move_enemy(vars, enemies, target);
	return (0);
}

int	get_enemy_target(t_ent *enemies, int target[2])
{
	target[X] = enemies->coords[X];
	target[Y] = enemies->coords[Y];
	if (enemies->id == 'H')
		target[X] += 1;
	else if (enemies->id == 'h')
		target[X] -= 1;
	else if (enemies->id == 'V')
		target[Y] += 1;
	else if (enemies->id == 'v')
		target[Y] -= 1;
	return (0);
}
