/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:11:42 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/25 14:02:01 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../dep/so_long.h"

int	draw(t_vars *vars)
{
	draw_background(vars);
	draw_entities(vars);
	draw_player(vars);
	update_move_counter(vars);
	return (0);
}

int	draw_background(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->images[BG], 0, 0);
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
