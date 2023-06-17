/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:30:35 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/13 19:16:16 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

int	key_pressed(int keycode, t_vars *vars)
{
	ft_printf("key pressed: %i\n", keycode);
	if (keycode == XK_Escape)
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
		quit(vars);
	}
	else if (keycode == XK_w || keycode == XK_a
					|| keycode == XK_s || keycode == XK_d)
		move_input(vars, keycode);
	draw_entities(vars);
	return (0);
}
