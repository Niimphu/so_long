/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_pathing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:32:44 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/24 17:34:55 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../dep/so_long.h"

char	**propagate_path(char **map);

int	check_map_pathing(char **map)
{
	int	coords[2];
	int	done;

	done = 0;
	if (!locate_first(map, 'P', coords))
		return (NO_PATH);
	while (!done)
	{
		if ((!locate_first(map, 'E', coords) && !locate_first(map, 'C', coords))
			|| !locate_first(map, 'P', coords))
		{
			done = 1;
			break ;
		}
		map = propagate_path(map);
	}
	if (locate_first(map, 'E', coords) || locate_first(map, 'C', coords))
		return (NO_PATH);
	return (OK);
}

char	**propagate_path(char **map)
{
	int	i;
	int	j;
	int	coords[2];

	i = locate_first(map, 'P', coords)[0];
	j = locate_first(map, 'P', coords)[1];
	if (map[i][j + 1] != '1' && map[i][j + 1] != 'X' && map[i][j + 1] != 'P')
		map[i][j + 1] = 'P';
	if (map[i][j - 1] != '1' && map[i][j - 1] != 'X' && map[i][j - 1] != 'P')
		map[i][j - 1] = 'P';
	if (map[i + 1][j] != '1' && map[i + 1][j] != 'X' && map[i + 1][j] != 'P')
		map[i + 1][j] = 'P';
	if (map[i - 1][j] != '1' && map[i - 1][j] != 'X' && map[i - 1][j] != 'P')
		map[i - 1][j] = 'P';
	map[i][j] = 'X';
	return (map);
}
