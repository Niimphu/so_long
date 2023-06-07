/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:15:08 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/07 20:18:54 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

int map_exists(char *name);
int map_check(char *name);
int	rectangle_check(char **map);

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

int map_exists(char *name)
{
	const int	fd = open(name, O_RDONLY, 0666);

	if (fd < 0)
		return (0);
	return (fd);
}

int map_check(char *name)
{
	const int	fd = map_exists(name);
	int 		error_code;
	char		**map;

	error_code = OK;
	if (!fd)
		return (MAP_NAME);
	map = read_map(fd);
	if (!(map))
		error_code = FAIL;
	else if (!rectangle_check(map))
		error_code = NOT_RECTANGLE;
	// else if (!valid_map_check(map))
	// 	error_code = BAD_MAP;
	close(fd);
	return (error_code);
}

int	rectangle_check(char **map)
{
	int		i;
	size_t	count;

	i = 0;
	count = ft_strlen(map[i++]);
	while (map[i])
	{
		if (ft_strlen(map[i++]) != count)
			return (0);
	}
	return (1);
}
