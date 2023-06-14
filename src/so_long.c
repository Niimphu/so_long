/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:16:58 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/14 19:11:17 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

#define PLAYER "../sprites/Player.png"

int	so_long(t_vars *vars)
{
	mlx_hook(vars->win, KeyPress, 1L << 0, key_pressed, vars);
	mlx_hook(vars->win, DestroyNotify, 0L, window_closed, vars);
	mlx_loop(vars->mlx);
	return (0);
}

// int	draw_something(t_vars *vars)
// {
// 	void	*img;

// 	img = mlx_png_file_to_image(mlx, PLAYER, &img_width, &img_height);
// }