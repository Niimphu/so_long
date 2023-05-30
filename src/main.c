/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:55:54 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/30 18:35:29 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

#define colour1 0x000000
#define colour2 0xFFFFFF


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "It's gamer time");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 0, 0, colour2);
	my_mlx_pixel_put(&img, 0, 1, colour2);
	my_mlx_pixel_put(&img, 0, 2, colour2);
	my_mlx_pixel_put(&img, 1, 2, colour2);
	my_mlx_pixel_put(&img, 2, 2, colour2);
	my_mlx_pixel_put(&img, 2, 1, colour2);
	my_mlx_pixel_put(&img, 2, 0, colour2);
	my_mlx_pixel_put(&img, 1, 0, colour2);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 10, 10);
	mlx_loop(mlx);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
