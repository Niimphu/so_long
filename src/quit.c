/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:54:03 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/14 14:35:47 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

int	window_closed(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	quit(vars);
	return (0);
}

void	quit(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	mlx_destroy_display(vars->mlx);
	free_ppointer(vars->map);
	exit(0);
}
