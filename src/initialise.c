/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:33:08 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/26 20:21:59 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

int	set_vars(t_vars *vars);
int	create_window(t_vars *vars);

int	initialise(char *name, t_vars *vars)
{
	vars->name = name;
	vars->enemies = NULL;
	if (new_map(vars) != OK)
		error_exit(FAIL);
	vars->mlx = mlx_init();
	create_window(vars);
	get_images_from_textures(vars);
	return (0);
}

int	new_map(t_vars *vars)
{
	int	fd;

	if (!vars->name)
		vars->name = "default";
	if (vars->map)
		free_ppointer(vars->map);
	fd = open_map_file(vars->name);
	if (fd < 0)
		return (FAIL);
	vars->map = read_map(fd, vars->name);
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
	vars->frame = 0;
	vars->move_count = 0;
	if (vars->enemies)
	{
		free_list(vars->enemies);
		vars->enemies = NULL;
	}
	vars->enemies = create_enemy_list(vars);
	return (0);
}

int	create_window(t_vars *vars)
{
	int	x;
	int	y;

	if (!ft_strncmp(vars->name, "default", 7))
	{
		x = 30 * 64;
		y = 15 * 64 + 18;
	}
	else
	{
		x = vars->map_size[X] * 64;
		y = vars->map_size[Y] * 64 + 18;
	}
	vars->win = mlx_new_window(vars->mlx, x, y, "so_looooong");
	return (0);
}
