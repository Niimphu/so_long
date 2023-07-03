/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:57:25 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/03 15:42:57 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../dep/so_long_bonus.h"

int	validate_map(char **map)
{
	if (check_map_rectangular(map))
		return (NON_RECT);
	if (check_entity_count(map))
		return (DUP_ENTITIES);
	if (check_map_border(map))
		return (BAD_BORDER);
	if (check_invalid_characters(map))
		return (INVALID_CHAR);
	if (check_map_pathing(map))
		return (NO_PATH);
	return (OK);
}
