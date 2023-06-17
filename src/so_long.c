/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:16:58 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/16 18:57:40 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

int	so_long(t_vars *vars)
{
	mlx_hook(vars->win, KeyPress, 1L << 0, key_pressed, vars);
	mlx_hook(vars->win, DestroyNotify, 0L, window_closed, vars);
//    draw_background(vars);
	draw_player(vars);
	mlx_loop(vars->mlx);
	return (0);
}
