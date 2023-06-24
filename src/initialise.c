/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:33:08 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/21 18:06:53 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

int	set_vars(t_vars *vars);
int	new_map(char *name, t_vars *vars);

int	initialise(char *name, t_vars *vars)
{
	int	x;
	int	y;

	if (new_map(name, vars) != OK)
		error_exit(FAIL);
	x = vars->map_size[X] * 64;
	y = vars->map_size[Y] * 64 + 18;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, x, y, "so_looooong");
	get_images_from_textures(vars);
	return (0);
}

int	new_map(char *name, t_vars *vars)
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
		error_exit(FAIL);
	set_vars(vars);
	return (OK);
}

int	set_vars(t_vars *vars)
{
	locate_first(vars->map, 'E', vars->exit_coords);
	get_map_size(vars->map, vars->map_size);
	count_collectibles(vars);
	vars->move_count = 0;
	return (0);
}
