/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:20:35 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/03 15:40:17 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long_bonus.h"

#define RED "\033[1;31m"
#define RESET "\033[1;0m"

char	*get_error_message(int error_code);

void	error_exit(int error_code)
{
	char	*error_message;

	write(2, RED, 8);
	write(2, "Error\n", 6);
	error_message = get_error_message(error_code);
	write(2, error_message, ft_strlen(error_message) * sizeof(char));
	write(2, RESET, 7);
	exit(error_code);
}

char	*get_error_message(int error_code)
{
	if (error_code == ARGN)
		return ("Too many arguments.\n");
	if (error_code == MAP_NAME)
		return ("Map not found.\n");
	if (error_code == BAD_MAP)
		return ("Map read failed.\n");
	if (error_code == NON_RECT)
		return ("Map is not rectangular.\n");
	if (error_code == DUP_ENTITIES)
		return ("Duplicate player or exits found.\n");
	if (error_code == NOT_ENOUGH_ENTITIES)
		return ("Map needs one Player and one Exit.\n");
	if (error_code == BAD_BORDER)
		return ("Map is not fully enclosed by walls.\n");
	if (error_code == NO_PATH)
		return ("No valid paths found.\n");
	if (error_code == INVALID_CHAR)
		return ("Unknown characters found in map.\n");
	return ("Undefined\n");
}
