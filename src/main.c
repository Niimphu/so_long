/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:55:54 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/14 14:49:57 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

int		init(char *name, t_vars *vars);

int	main(int argc, char **argv)
{
	int	error_code;
	t_vars	vars;

	ft_memset(&vars, 0, sizeof(vars));
	error_code = arg_check(argc, argv);
	if (error_code != OK)
		error(error_code);
	if (argc == 1)
		error_code = init(NULL, &vars);
	else
		error_code = init(argv[1], &vars);
	so_long(&vars);
	return (0);
}

int	init(char *name, t_vars *vars)
{
	int	fd;
	int	size[2];

	if (!name)
		fd = open_map_file("valid\0");
	else
		fd = open_map_file(name);
	if (fd < 0)
		return (FAIL);
	vars->map = read_map(fd);
	close(fd);
	vars->map_height = map_size(vars->map, size)[0];
	vars->map_width = map_size(vars->map, size)[1];
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->map_width * 64,
			vars->map_height * 64, "so_looooong");
	return (0);
}
