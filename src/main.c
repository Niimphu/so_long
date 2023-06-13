/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:55:54 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/13 19:13:25 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_gradient_box(t_vars *vars, int x, int y, unsigned int colour);

int		init(char *name, t_vars *vars);

int	main(int argc, char **argv)
{
	int	error_code;
	t_vars	vars;

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


	// draw_gradient_box(vars, 800, 800, red);









void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_gradient_box(t_vars *vars, int x, int y, unsigned int colour)
{
	t_data	img;
	int	i;
	int	j;

	img.img = mlx_new_image(vars->mlx, x, x);
	img.addr = mlx_get_data_addr(&img.img, &img.bits_per_pixel, \
		&img.line_length, &img.endian);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 10, 10);
	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
			my_mlx_pixel_put(&img, i++, j, colour);
		j++;
		if (!(j % 50) && colour != 0x00FFFFFF)
			colour += 4369;
	}
	return ;
}
