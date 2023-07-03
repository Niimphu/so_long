/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:22:17 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/03 15:42:08 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long_bonus.h"

int	so_long(t_bvars *vars)
{
	mlx_loop_hook(vars->mlx, loop, vars);
	mlx_hook(vars->win, KeyPress, 1L << 0, key_pressed, vars);
	mlx_hook(vars->win, DestroyNotify, 0L, window_closed, vars);
	update_move_counter(vars);
	mlx_loop(vars->mlx);
	return (0);
}
