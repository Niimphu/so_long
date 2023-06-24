/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:08:01 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/24 21:10:19 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../dep/so_long.h"

int	draw_player(t_vars *vars)
{
	int	coords[2];

	locate_first(vars->map, 'P', coords);
	mlx_put_image_to_window(vars->mlx, vars->win,vars->player_images[0],
							coords[X] * 64, coords[Y] * 64);
	return (0);
}
