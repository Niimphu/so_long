/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_characters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:08:01 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/03 15:42:40 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../dep/so_long_bonus.h"

int	draw_player(t_bvars *vars)
{
	int	coords[2];

	locate_first(vars->map, 'P', coords);
	if (!coords[X] || !coords[Y])
		return (1);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->player_images[vars->frame], coords[X] * 64, coords[Y] * 64);
	return (0);
}

int	draw_enemy(t_bvars *vars, int x, int y)
{
	x *= 64;
	y *= 64;
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->enemy_images[vars->frame], x, y);
	return (0);
}
