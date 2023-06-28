/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:21:36 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/25 14:21:36 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../dep/so_long_bonus.h"

void	update_frame(t_vars *vars);

int	loop(t_vars *vars)
{
	clock_t		time_since_start;
	static long	iterations;

	if (!iterations)
		iterations = 0;
	time_since_start = clock() / 50000;
	if (time_since_start > iterations)
	{
		iterations++;
		update_frame(vars);
	}
	return (0);
}

void	update_frame(t_vars *vars)
{
	vars->frame++;
	if (vars->frame > 7)
		vars->frame = 0;
	draw(vars);
}
