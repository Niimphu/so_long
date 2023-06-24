/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_rectangular.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:32:22 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/24 17:34:55 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../dep/so_long.h"

int	check_map_rectangular(char **map)
{
	int		i;
	size_t	count;

	i = 0;
	count = ft_strlen(map[i++]);
	while (map[i])
	{
		if (!map[i + 1] && ft_strlen(map[i]) == count - 1)
			return (OK);
		if (ft_strlen(map[i++]) != count)
			return (NON_RECT);
	}
	return (OK);
}
