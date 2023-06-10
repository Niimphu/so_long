/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:08:58 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/10 14:45:17 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			ft_printf("%c", map[i][j++]);
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
	return ;
}

int	*locate_first(char **map, char c, int coords[2])
{
	int	i;
	int	j;

	i = 0;
	coords[0] = 0;
	coords[1] = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				coords[0] = i;
				coords[1] = j;
			}
			j++;
		}
		i++;
	}
	if (!coords[0] || !coords[1])
		return (NULL);
	return (coords);
}

char	**propogate_path(char **map)
{
	int	i;
	int	j;
	int	coords[2];

	i = locate_first(map, 'P', coords)[0];
	j = locate_first(map, 'P', coords)[1];
	if (map[i][j + 1] != '1' && map[i][j + 1] != 'V' && map[i][j + 1] != 'P')
		map[i][j + 1] = 'P';
	if (map[i][j - 1] != '1' && map[i][j - 1] != 'V' && map[i][j - 1] != 'P')
		map[i][j - 1] = 'P';
	if (map[i + 1][j] != '1' && map[i + 1][j] != 'V' && map[i + 1][j] != 'P')
		map[i + 1][j] = 'P';
	if (map[i - 1][j] != '1' && map[i - 1][j] != 'V' && map[i - 1][j] != 'P')
		map[i - 1][j] = 'P';
	map[i][j] = 'V';
	return (map);
}
