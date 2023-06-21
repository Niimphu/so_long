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
#define BACKGROUND "sprites/BG.xpm"

int	draw_entity(t_vars *vars, int i, int j, int id);

int	draw_background(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->images[BG], 0, 0);
	return (0);
}

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
			if (vars->map[i][j] == 'P')
				draw_entity(vars, j, i, P);
			else if (vars->map[i][j] == 'C')
				draw_entity(vars, j, i, C);
			else if (vars->map[i][j] == 'E')
				draw_entity(vars, j, i, E);
			else if (vars->map[i][j] == '1')
				draw_entity(vars, j, i, W);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_images_from_textures(t_vars *vars)
{
	int	length;
	int	map_x;
	int	map_y;

	map_x = vars->map_size[X] * 64;
	map_y = vars->map_size[Y] * 64 + 18;
	vars->images[P]
		= mlx_xpm_file_to_image(vars->mlx, PLAYER, &length, &length);
	vars->images[E]
		= mlx_xpm_file_to_image(vars->mlx, EXIT, &length, &length);
	vars->images[C]
		= mlx_xpm_file_to_image(vars->mlx, COLLECTIBLE, &length, &length);
	vars->images[W]
		= mlx_xpm_file_to_image(vars->mlx, WALL, &length, &length);
	vars->images[BG]
		= mlx_xpm_file_to_image(vars->mlx, BACKGROUND, &map_x, &map_y);
	vars->images[5] = NULL;
	return (0);
}

int	update_move_counter(t_vars *vars)
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

int	draw_entity(t_vars *vars, int x, int y, int id)
{
	x *= 64;
	y *= 64;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->images[id], x, y);
	return (0);
}
