/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:54:03 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/12 16:37:35 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

int	window_closed(t_vars *vars)
{
	quit(vars);
	return (0);
}

void	quit(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	mlx_clear_window(vars->mlx, vars->win);
	// free_ppointer(vars->map_data->map);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}
