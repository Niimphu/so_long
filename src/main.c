/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:55:54 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/07 17:45:32 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_pressed(int keycode, t_vars *vars);
void	draw_gradient_rectangle(t_data *img, int x, int y, unsigned colour);
int 	init(void);

int	main(int argc, char **argv)
{
	int error_code;

	error_code = arg_check(argc, argv);
	if (error_code != OK)
		error(error_code);
	init();
	return (0);
}

int init(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "so_looooong");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_length, &img.endian);
	draw_gradient_rectangle(&img, 1000, 800, red);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 10, 10);
	mlx_hook(vars.win, KeyPress, 1L<<0, key_pressed, &vars);
	mlx_hook(vars.win, WindowClosed, 0L, window_closed, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int	key_pressed(int keycode, t_vars *vars)
{
	ft_printf("key pressed: %i\n", keycode);
	if (keycode == ESC)
		quit(vars);
	return (0);
}



#include <stdio.h>
void	draw_gradient_rectangle(t_data *img, int x, int y, unsigned colour)
{
	int i;
	int j;

	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
			my_mlx_pixel_put(img, i++, j, colour);
		j++;
		if (!(j % 50) && colour != 0x00FFFFFF)
			colour += 4369;
	}
	return ;
}
