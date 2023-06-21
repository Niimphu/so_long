/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:54:03 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/21 18:09:14 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

void	free_images(t_vars *vars);

int	window_closed(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	quit(vars);
	return (0);
}

void	quit(t_vars *vars)
{
	free_images(vars);
	mlx_loop_end(vars->mlx);
	mlx_destroy_display(vars->mlx);
	free_ppointer(vars->map);
	free(vars->mlx);
	exit(0);
}

void	free_images(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->images[i])
	{
		mlx_destroy_image(vars->mlx, vars->images[i]);
		i++;
	}
}
