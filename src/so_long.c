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

#define PLAYER "sprites/Player.xpm"
#define BG "sprites/Background.xpm"

int	draw_something(t_vars *vars);

int	so_long(t_vars *vars)
{
	mlx_hook(vars->win, KeyPress, 1L << 0, key_pressed, vars);
	mlx_hook(vars->win, DestroyNotify, 0L, window_closed, vars);
	draw_something(vars);
	mlx_loop(vars->mlx);
	return (0);
}

int	draw_something(t_vars *vars)
{
	void	*img;
	int		img_width = 64;
	int		img_height = 64;

	img = mlx_xpm_file_to_image(vars->mlx, PLAYER, &img_width, &img_height);
	if (!img)
	{
		ft_printf("No image loaded loser\n");
		quit(vars);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img, 0, 0);
	return (0);
}
