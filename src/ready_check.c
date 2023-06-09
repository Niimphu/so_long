/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:15:08 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/09 21:02:20 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

int	map_exists(char *name);

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
	const int	fd = map_exists(name);
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

int	map_exists(char *name)
{
	int		fd;
	char	*temp;

	temp = ft_strjoin(name, ".ber");
	name = ft_strjoin("maps/", temp);
	free_pointer(temp);
	fd = open(name, O_RDONLY, 0666);
	free_pointer(name);
	if (fd < 0)
		return (0);
	return (fd);
}
