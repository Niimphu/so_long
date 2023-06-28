/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:40:04 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/28 22:56:38 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

int	move_enemy(t_vars *vars, t_ent *enemies);
int	flip_enemy(t_vars *vars, t_ent *enemies);

int	move_enemies(t_vars *vars)
{
	t_ent	*enemies;

	enemies = vars->enemies;
	while (enemies)
	{
		move_enemy(vars, enemies);
		enemies = enemies->next;
	}
	return (0);
}

int	move_enemy(t_vars *vars, t_ent *enemies)
{
	int	target[2];

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
	else
		return (0);
	if (vars->map[target[Y]][target[X]] == 'P')
		return (new_map(vars));
	if (is_enemy_move_valid(vars, target[Y], target[X]))
	{
		vars->map[target[Y]][target[X]] = enemies->id;
		vars->map[enemies->coords[Y]][enemies->coords[X]] = '0';
		enemies->coords[X] = target[X];
		enemies->coords[Y] = target[Y];
	}
	else
		flip_enemy(vars, enemies);
	return (0);
}

int	flip_enemy(t_vars *vars, t_ent *enemies)
{
	if (enemies->id == 'H')
		enemies->id = 'h';
	else if (enemies->id == 'h')
		enemies->id = 'H';
	else if (enemies->id == 'V')
		enemies->id = 'v';
	else if (enemies->id == 'v')
		enemies->id = 'V';
	move_enemy(vars, enemies);
	return (0);
}
