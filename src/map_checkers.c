/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:57:25 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/10 15:04:55 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

int	is_rectangular(char **map);
int	has_no_duplicates(char **map);
int	has_continuous_border(char **map);
int	has_valid_path(char **map);

int	is_map_valid(char **map)
{
	if (!is_rectangular(map) || !has_no_duplicates(map)
		|| !has_continuous_border(map) || !has_valid_path(map))
		return (FALSE);
	return (TRUE);
}

int	is_rectangular(char **map)
{
	int		i;
	size_t	count;

	i = 0;
	count = ft_strlen(map[i++]);
	while (map[i])
	{
		if (ft_strlen(map[i++]) != count)
			return (FALSE);
	}
	return (TRUE);
}

int	has_no_duplicates(char **map)
{
	int	player_count;
	int	exit_count;
	int	i;
	int	j;

	player_count = 0;
	exit_count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				player_count++;
			if (map[i][j++] == 'E')
				exit_count++;
			if (player_count > 1 || exit_count > 1)
				return (FALSE);
		}
		i++;
	}
	if (player_count != 1 || exit_count != 1)
		return (FALSE);
	return (TRUE);
}

int	has_continuous_border(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[0][j + 1])
		j++;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][j] != '1')
			return (FALSE);
		i++;
	}
	i--;
	while (map[0][j] && map[i][j])
	{
		if (map[0][j] != '1' || map[i][j--] != '1')
			return (FALSE);
	}
	return (TRUE);
}

int	has_valid_path(char **map)
{
	int	i;
	int	j;
	int	coords[2];
	int	done;

	done = 0;
	if (!locate_first(map, 'P', coords))
		return (FALSE);
	i = locate_first(map, 'P', coords)[0];
	j = locate_first(map, 'P', coords)[1];
	while (!done)
	{
		if ((!locate_first(map, 'E', coords) && !locate_first(map, 'C', coords))
			|| !locate_first(map, 'P', coords))
		{
			done = 1;
			break ;
		}
		map = propogate_path(map);
	}
	if (locate_first(map, 'E', coords) || locate_first(map, 'C', coords))
		return (FALSE);
	return (TRUE);
}