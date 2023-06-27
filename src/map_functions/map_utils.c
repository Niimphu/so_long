/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:08:58 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/26 20:21:43 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../dep/so_long.h"

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
	if (coords[0] == 0 && coords[1] == 0)
		return (NULL);
	return (coords);
}

int	count_collectibles(t_vars *vars)
{
	int	i;
	int	j;

	vars->collectible_count = 0;
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'C')
				vars->collectible_count += 1;
			j++;
		}
		i++;
	}
	return (0);
}

int	*get_map_size(char **map, int size[2])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i + 1])
		i++;
	while (map[i][j + 1])
		j++;
	size[0] = ++i;
	size[1] = ++j;
	return (size);
}

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
}
