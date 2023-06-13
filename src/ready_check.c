/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:15:08 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/13 17:15:15 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

int	arg_check(int argc, char **argv)
{
	int	error_code;

	if (argc == 1)
		return (0);
	else if (argc >= 3)
		return (ARGN);
	error_code = map_check(argv[argc - 1]);
	if (error_code != OK)
		return (error_code);
	return (OK);
}

int	map_check(char *name)
{
	const int	fd = open_map_file(name);
	int			error_code;
	char		**map;

	error_code = OK;
	if (!fd)
		return (MAP_NAME);
	map = read_map(fd);
	if (!(map))
		error_code = BAD_MAP;
	else if (!is_map_valid(map))
		error_code = BAD_MAP;
	close(fd);
	free_ppointer(map);
	return (error_code);
}
