/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:33:08 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/21 13:19:41 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

int set_vars(t_vars *vars);
int new_map(char *name, t_vars *vars);

int	init(char *name, t_vars *vars)
{
	new_map(name, vars);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->map_size[X] * 64,
							   vars->map_size[Y] * 64 + 18, "so_looooong");
	get_images_from_textures(vars);
	return (0);
}

int new_map(char *name, t_vars *vars)
{
	int	fd;

	if (!name)
		name = "valid\0";
	fd = open_map_file(name);
	if (fd < 0)
		return (FAIL);
	vars->map = read_map(fd, name);
	close(fd);
	if (!vars->map)
		error(FAIL);
	set_vars(vars);
	return (0);
}

int set_vars(t_vars *vars)
{
	locate_first(vars->map, 'E', vars->exit_coords);
	get_map_size(vars->map, vars->map_size);
	count_collectibles(vars);
	vars->move_count = 0;
	return (0);
}

int count_collectibles(t_vars *vars)
{
	int i;
	int j;

	vars->collectible_count = 0;
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'C')
				vars->collectible_count += 1;
			j++;
		}
		i++;
	}
	return (0);
}