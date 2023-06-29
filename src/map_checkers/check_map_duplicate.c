/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_duplicate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:32:37 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/24 17:34:55 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../dep/so_long.h"

int	check_entity_count(char **map)
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
			player_count += (map[i][j] == 'P');
			exit_count += (map[i][j++] == 'E');
			if (player_count > 1 || exit_count > 1)
				return (DUP_ENTITIES);
		}
		i++;
	}
	if (player_count > 1 || exit_count > 1)
		return (DUP_ENTITIES);
	if (player_count < 1 || exit_count < 1)
		return (NOT_ENOUGH_ENTITIES);
	return (OK);
}
