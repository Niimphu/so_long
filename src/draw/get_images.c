/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:46:05 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/24 21:32:10 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../dep/so_long.h"

#define PLAYER "sprites/Player.xpm"
#define PLAYER2 "sprites/Player2.xpm"
#define COLLECTIBLE "sprites/Collectible.xpm"
#define EXIT "sprites/Exit.xpm"
#define WALL "sprites/Wall.xpm"
#define BACKGROUND "sprites/BG.xpm"

void	*get_image(t_vars *vars, char *path_to_file, int x, int y);

int	get_images_from_textures(t_vars *vars)
{
	int	length;
	int	map_x;
	int	map_y;

	length = 64;
	map_x = vars->map_size[X] * 64;
	map_y = vars->map_size[Y] * 64 + 18;
	vars->player_images[0] = get_image(vars, PLAYER, length, length);
	vars->player_images[1] = get_image(vars, PLAYER2, length, length);
	vars->player_images[2] = NULL;
	vars->images[E] = get_image(vars, EXIT, length, length);
	vars->images[C] = get_image(vars, COLLECTIBLE, length, length);
	vars->images[W] = get_image(vars, WALL, length, length);
	vars->images[BG] = get_image(vars, BACKGROUND, map_x, map_y);
	vars->images[4] = NULL;
	return (0);
}

void	*get_image(t_vars *vars, char *path_to_file, int x, int y)
{
	return (mlx_xpm_file_to_image(vars->mlx, path_to_file, &x, &y));
}
