/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:30:35 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/10 15:31:39 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

int	key_pressed(int keycode, t_vars *vars)
{
	ft_printf("key pressed: %i\n", keycode);
	if (keycode == ESC)
		quit(vars);
	return (0);
}
