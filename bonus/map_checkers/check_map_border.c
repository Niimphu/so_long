/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_border.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:32:40 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/03 15:42:57 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../dep/so_long_bonus.h"

int	check_map_border(char **map)
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
			return (BAD_BORDER);
		i++;
	}
	i--;
	j = 0;
	while (map[0][j] && map[i][j])
	{
		if (map[0][j] != '1' || map[i][j] != '1')
			return (BAD_BORDER);
		j++;
	}
	return (OK);
}
