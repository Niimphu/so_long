/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:30:35 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/26 20:21:55 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

int	key_pressed(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
		quit(vars);
	}
	else if (keycode == XK_w || keycode == XK_a ||
		keycode == XK_s || keycode == XK_d ||
		keycode == XK_Up || keycode == XK_Right ||
		keycode == XK_Left || keycode == XK_Down)
		move_input(vars, keycode);
	draw(vars);
	update_move_counter(vars);
	return (0);
}
