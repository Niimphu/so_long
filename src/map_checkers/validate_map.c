/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:57:25 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/24 17:34:55 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../dep/so_long.h"

int	validate_map(char **map)
{
	if (check_map_rectangular(map))
		return (check_map_rectangular(map));
	if (check_map_duplicate_entities(map))
		return (check_map_duplicate_entities(map));
	if (check_map_border(map))
		return (check_map_border(map));
	if (check_map_pathing(map))
		return (check_map_pathing(map));
	return (OK);
}
