/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:22:17 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/25 15:24:23 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../dep/so_long.h"

int	so_long(t_vars *vars)
{
	mlx_loop_hook(vars->mlx, loop, vars);
	mlx_hook(vars->win, KeyPress, 1L << 0, key_pressed, vars);
	mlx_hook(vars->win, DestroyNotify, 0L, window_closed, vars);
	update_move_counter(vars);
	mlx_loop(vars->mlx);
	return (0);
}
