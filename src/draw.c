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
#define COLLECTIBLE "sprites/Collectible.xpm"
#define EXIT "sprites/Exit.xpm"
#define WALL "sprites/Wall.xpm"
#define BG "sprites/BG.xpm"

#define P 0
#define E 1
#define C 2
#define W 3

int	get_images_from_textures(t_vars *vars, void *images[5]);

int	draw_background(t_vars *vars)
{
	void	*img;
	int 	width = 1920;
	int 	height = 1080;

	img = mlx_xpm_file_to_image(vars->mlx, BG, &width, &height);
	mlx_put_image_to_window(vars->mlx, vars->win, img, 0, 0);
	return (0);
}

int draw_entities(t_vars *vars)
{
	void	*images[5];
	int 	i;
	int 	j;

	draw_background(vars);
	get_images_from_textures(vars, images);
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win,
										images[P],64 * j, 64 * i);
			else if (vars->map[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win,
										images[C],64 * j, 64 * i);
			else if (vars->map[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win,
										images[E],64 * j, 64 * i);
			else if (vars->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win,
										images[W],64 * j, 64 * i);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_images_from_textures(t_vars *vars, void *images[5])
{
	int length;

	length = 64;
	images[P] = mlx_xpm_file_to_image(vars->mlx, PLAYER, &length, &length);
	images[E] = mlx_xpm_file_to_image(vars->mlx, EXIT, &length, &length);
	images[C] = mlx_xpm_file_to_image(vars->mlx, COLLECTIBLE, &length, &length);
	images[W] = mlx_xpm_file_to_image(vars->mlx, WALL, &length, &length);
	vars->player_image = images[P];
	return (0);
}

int update_move_counter(t_vars *vars)
{
	char	*count_string;
	char	*print_string;

	count_string = ft_itoa(vars->move_count);
	print_string = ft_strjoin("Moves: ", count_string);
	mlx_string_put(vars->mlx, vars->win, 12,
				   vars->map_size[Y] * 64 + 12, 0x00000000, print_string);
	free_pointer(count_string);
	free_pointer(print_string);
	return (0);
}
