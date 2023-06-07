/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:20:35 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/07 20:20:17 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

void error(int error_code)
{
	write(2, RED, 8);
	if (error_code == ARGN)
		write(2, "Error\nToo many arguments\n", 25);
	else if (error_code == MAP_NAME)
		write(2, "Error\nInvalid file name argument\n", 23);
	else if (error_code == BAD_MAP)
		write(2, "Error\nInvalid map\n", 18);
	else if (error_code == NOT_RECTANGLE)
		write(2, "Error\nMap is not rectangular\n", 29);
	else
		write(2, "Error\nUndefined\n", 16);
	write(2, RESET, 7);
	exit(error_code);
}
