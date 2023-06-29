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

#define PLAYER "sprites/Player/Player4.xpm"
#define PLAYER2 "sprites/Player/Player3.xpm"
#define PLAYER3 "sprites/Player/Player2.xpm"
#define PLAYER4 "sprites/Player/Player.xpm"
#define PLAYER5 "sprites/Player/Player.xpm"
#define PLAYER6 "sprites/Player/Player2.xpm"
#define PLAYER7 "sprites/Player/Player3.xpm"
#define PLAYER8 "sprites/Player/Player4.xpm"
#define ENEMY "sprites/Enemy/Enemy3.xpm"
#define ENEMY2 "sprites/Enemy/Enemy4.xpm"
#define ENEMY3 "sprites/Enemy/Enemy5.xpm"
#define ENEMY4 "sprites/Enemy/Enemy6.xpm"
#define ENEMY5 "sprites/Enemy/Enemy4.xpm"
#define ENEMY6 "sprites/Enemy/Enemy3.xpm"
#define ENEMY7 "sprites/Enemy/Enemy.xpm"
#define ENEMY8 "sprites/Enemy/Enemy2.xpm"
#define EXPLOSION "sprites/Explosion/Explosion.xpm"
#define EXPLOSION2 "sprites/Explosion/Explosion2.xpm"
#define EXPLOSION3 "sprites/Explosion/Explosion3.xpm"
#define EXPLOSION4 "sprites/Explosion/Explosion4.xpm"
#define EXPLOSION5 "sprites/Explosion/Explosion5.xpm"
#define EXPLOSION6 "sprites/Explosion/Explosion6.xpm"
#define EXPLOSION7 "sprites/Explosion/Explosion7.xpm"
#define EXPLOSION8 "sprites/Explosion/Explosion8.xpm"
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
void	*load_enemy_images(t_vars *vars, int length);
void	*load_explosion_images(t_vars *vars, int length);

int	get_images_from_textures(t_vars *vars)
{
	int	length;
	int	map_x;
	int	map_y;

	length = 64;
	map_x = vars->map_size[X] * 64;
	map_y = vars->map_size[Y] * 64 + 18;
	load_player_images(vars, length);
	load_enemy_images(vars, length);
	load_explosion_images(vars, length);
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

void	*load_enemy_images(t_vars *vars, int length)
{
	vars->enemy_images[0] = get_image(vars, ENEMY, length, length);
	vars->enemy_images[1] = get_image(vars, ENEMY2, length, length);
	vars->enemy_images[2] = get_image(vars, ENEMY3, length, length);
	vars->enemy_images[3] = get_image(vars, ENEMY4, length, length);
	vars->enemy_images[4] = get_image(vars, ENEMY5, length, length);
	vars->enemy_images[5] = get_image(vars, ENEMY6, length, length);
	vars->enemy_images[6] = get_image(vars, ENEMY7, length, length);
	vars->enemy_images[7] = get_image(vars, ENEMY8, length, length);
	vars->enemy_images[8] = NULL;
	return (NULL);
}

void	*load_explosion_images(t_vars *vars, int length)
{
	vars->explosion_images[0] = get_image(vars, EXPLOSION, length, length);
	vars->explosion_images[1] = get_image(vars, EXPLOSION2, length, length);
	vars->explosion_images[2] = get_image(vars, EXPLOSION3, length, length);
	vars->explosion_images[3] = get_image(vars, EXPLOSION4, length, length);
	vars->explosion_images[4] = get_image(vars, EXPLOSION5, length, length);
	vars->explosion_images[5] = get_image(vars, EXPLOSION6, length, length);
	vars->explosion_images[6] = get_image(vars, EXPLOSION7, length, length);
	vars->explosion_images[7] = get_image(vars, EXPLOSION8, length, length);
	vars->explosion_images[8] = NULL;
	return (NULL);
}
