/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 00:57:58 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/17 03:50:31 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../dep/so_long.h"

int	draw_collectible(t_vars *vars, int x, int y);
int	draw_exit(t_vars *vars, int x, int y);
int	draw_wall(t_vars *vars, int x, int y);

int	draw_entities(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'C')
				draw_collectible(vars, j, i);
			else if (vars->map[i][j] == 'E')
				draw_exit(vars, j, i);
			else if (vars->map[i][j] == '1')
				draw_wall(vars, j, i);
			else if (vars->map[i][j] == 'H' || vars->map[i][j] == 'V')
				draw_enemy(vars, j, i);
			j++;
		}
		i++;
	}
	return (0);
}

int	draw_wall(t_vars *vars, int x, int y)
{
	x *= 64;
	y *= 64;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, x, y);
	return (0);
}


int	draw_collectible(t_vars *vars, int x, int y)
{
	x *= 64;
	y *= 64;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->collectible_images[vars->frame % 4], x, y);
	return (0);
}

int	draw_exit(t_vars *vars, int x, int y)
{
	x *= 64;
	y *= 64;

	if (!vars->collectible_count)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit_images[1], x, y);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit_images[0], x, y);
	return (0);
}
