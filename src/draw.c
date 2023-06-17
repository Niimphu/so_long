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

#include "../dep/so_long.h"

#define PLAYER "sprites/Player.xpm"
#define BG "sprites/Background.xpm"

#define P 0
#define E 1
#define C 2
#define W 3
#define G 4

int	draw_background(t_vars *vars)
{
	void	*img;
	int 	length = 64;
	int 	i;
	int 	j;

	img = mlx_xpm_file_to_image(vars->mlx, BG, &length, &length);
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			mlx_put_image_to_window(vars->mlx, vars->win, img,
				64 * j, 64 * i);
			j++;
		}
		i++;
	}
	return (0);
}

int	draw_player(t_vars *vars)
{
    void	*img;
    int 	length = 64;
	int 	coords[2];

	locate_first(vars->map, 'P', coords);
	img = mlx_xpm_file_to_image(vars->mlx, PLAYER, &length, &length);
    mlx_put_image_to_window(vars->mlx, vars->win, img,
							64 * coords[X], 64 * coords[Y]);
    return (0);
}
