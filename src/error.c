/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:20:35 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/11 15:42:33 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

# define RED "\033[1;31m"
# define RESET "\033[1;0m"

void	error(int error_code)
{
	int	ret;

	ret = write(2, RED, 8);
	if (error_code == ARGN)
		ret = write(2, "Error\nToo many arguments\n", 25);
	else if (error_code == MAP_NAME)
		ret = write(2, "Error\nInvalid argument\n", 23);
	else if (error_code == BAD_MAP)
		ret = write(2, "Error\nInvalid map\n", 18);
	else
		ret = write(2, "Error\nUndefined\n", 16);
	ret = write(2, RESET, 7);
	if (ret < 0)
		exit(error_code);
	exit(error_code);
}
