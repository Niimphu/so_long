/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:46:05 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/03 15:27:04 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../dep/so_long.h"

#define PLAYER "sprites/Player/Player4.xpm"
#define PLAYER2 "sprites/Player/Player3.xpm"
#define PLAYER3 "sprites/Player/Player2.xpm"
#define PLAYER4 "sprites/Player/Player.xpm"
#define PLAYER5 "sprites/Player/Player.xpm"
#define PLAYER6 "sprites/Player/Player2.xpm"
#define PLAYER7 "sprites/Player/Player3.xpm"
#define PLAYER8 "sprites/Player/Player4.xpm"
#define COLLECTIBLE "sprites/Collectible/Collectible.xpm"
#define COLLECTIBLE2 "sprites/Collectible/Collectible2.xpm"
#define COLLECTIBLE3 "sprites/Collectible/Collectible3.xpm"
#define COLLECTIBLE4 "sprites/Collectible/Collectible4.xpm"
#define EXIT "sprites/Exit/Exit.xpm"
#define EXIT2 "sprites/Exit/Exit2.xpm"
#define WALL "sprites/Wall.xpm"
#define BACKGROUND "sprites/BG.xpm"

void	*get_image(t_vars *vars, char *path_to_file, int x, int y);
void	*load_player_images(t_vars *vars, int length);

int	get_images_from_textures(t_vars *vars)
{
	int	length;
	int	map_x;
	int	map_y;

	length = 64;
	map_x = vars->map_size[X] * 64;
	map_y = vars->map_size[Y] * 64 + 18;
	load_player_images(vars, length);
	vars->exit_images[0] = get_image(vars, EXIT, length, length);
	vars->exit_images[1] = get_image(vars, EXIT2, length, length);
	vars->exit_images[2] = NULL;
	vars->collectible_images[0] = get_image(vars, COLLECTIBLE, length, length);
	vars->collectible_images[1] = get_image(vars, COLLECTIBLE2, length, length);
	vars->collectible_images[2] = get_image(vars, COLLECTIBLE3, length, length);
	vars->collectible_images[3] = get_image(vars, COLLECTIBLE4, length, length);
	vars->collectible_images[4] = NULL;
	vars->wall = get_image(vars, WALL, map_x, map_y);
	vars->background = get_image(vars, BACKGROUND, map_x, map_y);
	return (0);
}

void	*get_image(t_vars *vars, char *path_to_file, int x, int y)
{
	return (mlx_xpm_file_to_image(vars->mlx, path_to_file, &x, &y));
}

void	*load_player_images(t_vars *vars, int length)
{
	vars->player_images[0] = get_image(vars, PLAYER, length, length);
	vars->player_images[1] = get_image(vars, PLAYER2, length, length);
	vars->player_images[2] = get_image(vars, PLAYER3, length, length);
	vars->player_images[3] = get_image(vars, PLAYER4, length, length);
	vars->player_images[4] = get_image(vars, PLAYER5, length, length);
	vars->player_images[5] = get_image(vars, PLAYER6, length, length);
	vars->player_images[6] = get_image(vars, PLAYER7, length, length);
	vars->player_images[7] = get_image(vars, PLAYER8, length, length);
	vars->player_images[8] = NULL;
	return (NULL);
}
