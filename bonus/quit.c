/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:54:03 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/03 15:48:17 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long_bonus.h"

void	free_images(t_bvars *vars);

int	window_closed(t_bvars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	quit(vars);
	return (0);
}

void	quit(t_bvars *vars)
{
	if (vars->enemies)
		free_list(vars->enemies);
	mlx_loop_end(vars->mlx);
	free_images(vars);
	mlx_destroy_display(vars->mlx);
	free_ppointer(vars->map);
	free(vars->mlx);
	exit(0);
}

void	free_images(t_bvars *vars)
{
	int	i;

	i = 0;
	while (vars->collectible_images[i])
	{
		mlx_destroy_image(vars->mlx, vars->collectible_images[i]);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		mlx_destroy_image(vars->mlx, vars->player_images[i]);
		mlx_destroy_image(vars->mlx, vars->enemy_images[i]);
		mlx_destroy_image(vars->mlx, vars->explosion_images[i]);
		i++;
	}
	i = 0;
	while (vars->exit_images[i])
	{
		mlx_destroy_image(vars->mlx, vars->exit_images[i]);
		i++;
	}
	mlx_destroy_image(vars->mlx, vars->wall);
	mlx_destroy_image(vars->mlx, vars->background);
}
